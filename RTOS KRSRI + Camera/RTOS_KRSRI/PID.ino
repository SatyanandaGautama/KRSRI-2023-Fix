void Baca_kompas() {
  Wire2.beginTransmission(CMPS12_ADDRESS);
  Wire2.write(1); // Read dari Register 1
  Wire2.endTransmission();
  Wire2.requestFrom(CMPS12_ADDRESS, 3); // Request 3 Byte
  while (Wire2.available() < 3);
  Wire2.read();
  highBytes = Wire2.read(); // REG 2
  lowBytes = Wire2.read();  // REG 3
  tempt = highBytes;                 // Calculate 16 bit angle
  tempt <<= 8;
  tempt += lowBytes;
  tempt /= 10;
  heading = tempt;
  arah = heading - calKompas;
  if (arah < 0) arah += 360;
  if (arah > 360) arah -= 360;

  compassOffset = arah - compassStart;

  if (compassStart == compassFront[0]) {
    //jika acuan utara > 325
    if (arah < 45) {
      compassOffset = (arah - compassFront[0]) + 360; // nilai + (agar rotate kanan)
    }
    //jika acuan utara < 45
    //    if (arah > 325) {
    //      compassOffset = ((arah - compassFront[0]) - 360); // nilai + (agar rotate kanan)
    //    }
    else {
      compassOffset = arah - compassFront[0];// nilai -
    }
  }

  //Arena Biru rotate U ke T safety zone 1 (bolak balik)
  if (compassStart == 345) {
    if (arah < 90) {
      compassOffset = (arah - 345) + 360; //supaya rotate kiri
    }
  }

  if (compassStart == compassFront[1] - 3) {
    if (arah > 325) {
      compassOffset = (arah - (compassFront[1] - 3)) - 360; //supaya rotate kanan
    }
  }

  if (compassStart == compassFront[3]) {
    if (arah < 45) {
      compassOffset = 360 - compassFront[3] + arah; // nilai +
    }
    else {
      compassOffset = arah - compassFront[3];// nilai -
    }
  }

  if (compassOffset > 40) compassOffset = 40;//40
  else if (compassOffset < -40) compassOffset = -40;//40
  //  DEBUG_SERIAL.print("Arah : ");
  //  DEBUG_SERIAL.println(arah);
  //  DEBUG_SERIAL.print("Offset : ");
  //  DEBUG_SERIAL.println(compassOffset);
  vTaskDelay(10 / portTICK_PERIOD_MS);
}

void calculate_pid(bool pidchoice, int belok) {

  P_control = kp * error;

  I_control = I_control + (ki * error);
  if (I_control > 5) {
    I_control = 5;
  }
  else if (I_control < -5) {
    I_control = -5;
  }

  D_control = kd * (error - previous_error);

  pid_output = P_control + I_control + D_control;

  if (pidchoice == true)sudutBelok = pid_output;  //Mundur & Geser Kanan
  else if (pidchoice == false)sudutBelok = pid_output * -1; //Maju & Geser Kiri

  // Pembatas Sudut Maks = 5, Min = 3
  if (sudutBelok >= belok)sudutBelok = belok;
  else if (sudutBelok <= belok * -1)sudutBelok = belok * -1;
  previous_error = error;
}

void navigasilurus(bool pidmode, int sdtbelok) {
  Baca_kompas();
  //Penentuan Setpoint
  //Kondisi Acuan Utara :
  //klo acuan < 45 = yang > 325 + 360
  //klo acuan > 325 = yang < 45 - 360
  if (arah < 45) {
    //    sp_kompas = compassFront[0] + 3;
    error = (sp_kompas - arah) - 360; //nilai - agar rotate kiri
  }
  else if (arah >= 325) {
    //    sp_kompas = compassFront[0] + 3;
    error = sp_kompas - arah;
  }
  else if (arah >= 45 && arah < 120) {
    //    sp_kompas = compassFront[1] - 11; //acuan timur
    error = sp_kompas - arah;
  }
  else if (arah >= 120 && arah < 215) {
    //    sp_kompas = compassFront[2] - 9; //acuan selatan //-3 utk Invers //+2 utk non inverse
    error = sp_kompas - arah;
  }
  else if (arah >= 215 && arah < 325) {
    //    sp_kompas = compassFront[3] - 7; //acuan barat //11 utk di Inverse Arena
    error = sp_kompas - arah;
  }

  calculate_pid(pidmode, sdtbelok);
  //  DEBUG_SERIAL.print("SP : ");
  //  DEBUG_SERIAL.println(sp_kompas);
  //  DEBUG_SERIAL.print("ERROR : ");
  //  DEBUG_SERIAL.println(error);
  //  DEBUG_SERIAL.print(",");
  //  DEBUG_SERIAL.println(sudutBelok);
}

void readPitch() {
  pitch = getPitch();
  DEBUG_SERIAL.print(pitch);
  DEBUG_SERIAL.println(" degree,");
  vTaskDelay(15 / portTICK_PERIOD_MS);
}

byte getPitch() {
  // Begin communication with CMPS12
  Wire2.beginTransmission(CMPS12_ADDRESS);
  Wire2.write(4);
  Wire2.endTransmission();
  // Request 1 byte from CMPS12
  Wire2.requestFrom(CMPS12_ADDRESS , 1);
  // Read the values
  char _pitch = Wire2.read();
  return _pitch;
}

void susurkiriV1(float SpLeft, float sdtbelok) {
  readIRRange_0();
  readIRRange_4();
  pv = min(IRRangeVal_0, (IRRangeVal_4 + 1));
  if (IRRangeVal_0 != IRRangeVal_4) {
    error = abs(SpLeft - pv);
    PIDJarak();
    if (IRRangeVal_0 < IRRangeVal_4)longStep = pid_output * -1;
    else if (IRRangeVal_4 < IRRangeVal_0) longStep = pid_output;
  }
  else if (IRRangeVal_0 == IRRangeVal_4) {
    error = SpLeft - pv;
    PIDJarak();
    longStep = pid_output;
  }
  //belok kiri = sudut belok (+)
  //belok kanan = sudut belok (-)
  if (longStep >= sdtbelok)longStep = sdtbelok;
  else if (longStep <= sdtbelok * -1)longStep = sdtbelok * -1;
  DEBUG_SERIAL.print("pv = ");
  DEBUG_SERIAL.println(pv);
  DEBUG_SERIAL.print("error = ");
  DEBUG_SERIAL.println(error);
  DEBUG_SERIAL.print("longStep = ");
  DEBUG_SERIAL.println(longStep);
}

void susurkiriV2(float sdtbelok) {
  //  baca_ping();
  //  pv = min(jarak[0], jarak[1] * 0.5);
  readIRRange_0();
  readIRRange_4();
  error = IRRangeVal_0 - (IRRangeVal_4 + 1);
  PIDJarak();
  longStep = pid_output;
  if (longStep >= sdtbelok)longStep = sdtbelok;
  else if (longStep <= sdtbelok * -1)longStep = sdtbelok * -1;
  Serial2.print("error = ");
  Serial2.println(error);
  Serial2.print("longStep = ");
  Serial2.println(longStep);
}

void susurkiriV3(float sdtbelok) {
  readIRRange_0();
  readIRRange_4();
  error = IRRangeVal_0 - (IRRangeVal_4 - 2);
  PIDJarak();
  longStep = pid_output;
  if (longStep >= sdtbelok)longStep = sdtbelok;
  else if (longStep <= sdtbelok * -1)longStep = sdtbelok * -1;
  Serial2.print("error = ");
  Serial2.println(error);
  Serial2.print("longStep = ");
  Serial2.println(longStep);
}

void PIDJarak() {
  P_control = kp * error;
  I_control = I_control + (ki * error);
  if (I_control > 3) {
    I_control = 3;
  }
  else if (I_control < -3) {
    I_control = -3;
  }
  D_control = kd * (error - previous_error);
  pid_output = P_control + I_control + D_control;
  previous_error = error;
}



void resetPID() {
  P_control = 0;
  I_control = 0;
  D_control = 0;
  error = 0;
  previous_error = 0;
  pid_output = 0;
}
