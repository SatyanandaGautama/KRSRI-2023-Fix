void deteksiK1Inverse() {
  compassStart = compassFront[2];
  Baca_kompas();
  while (abs(compassOffset) >= 8) {
    if (compassOffset < 0) {
      command("rotateRightStart", 18, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else if (compassOffset > 0) {
      command("rotateLeftStart", 19, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    Baca_kompas();
  }
  readIRRange_4();
  while (IRRangeVal_4 <= 8) {
    command("maju", 5, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_4();
  }
  //============Turun Capit===============//
  vTaskDelay(300 / portTICK_PERIOD_MS); //200
  command("turun_capit", 11, true);
  command("kosong", 35, false);
  vTaskDelay(900 / portTICK_PERIOD_MS); //840
  //============Turun Capit===============//
  //==========Deteksi Korban 1 Inverse===========//
  compassStart = 129;
  sp_kompas = 129; //di set lurus ke arah korban
  while (1) {
    Baca_kompas();
    vTaskDelay(20 / portTICK_PERIOD_MS);
    read_maix();
    vTaskDelay(20 / portTICK_PERIOD_MS);
    if (abs(compassOffset) >= 12 ) { //12
      if (compassOffset < 0) {
        command("rotateRightK1", 42, false);
        vTaskDelay(35 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kanan : ");
        DEBUG_SERIAL.println(compassOffset);
      }
      else if (compassOffset > 0) {
        command("rotateLeftK1", 43, false);
        vTaskDelay(35 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kiri : ");
        DEBUG_SERIAL.println(compassOffset);
      }
    }
    else if (pict_x < 172 - 9) {     //orang di sebelah kiri// non inverse arena = - 7
      navigasilurus(false, 4);
      command("geser_kiri_dikit", 8, false);
      vTaskDelay(25 / portTICK_PERIOD_MS);
      //      }
    }
    else if (pict_x > 172 + 7) {//orang di sebelah kanan// non inverse arena = + 9
      navigasilurus(true, 4);
      command("geser_kanan_dikit", 7, false);
      vTaskDelay(25 / portTICK_PERIOD_MS);
      //      }
    }
    else if (area < 8050) { //orang di tengah tapi jauh //7800
      //      navigasilurus(false, 2);
      command("maju_dikit", 5, false);
      vTaskDelay(40 / portTICK_PERIOD_MS);
    }
    else if (area > 7800  + 2100) { //7500 + 2200
      //      navigasilurus(true, 2);
      command("mundur_dikit", 6, false);
      vTaskDelay(40 / portTICK_PERIOD_MS);
    }
    else {
      command("grabK1", 10, true);
      vTaskDelay(20 / portTICK_PERIOD_MS);
      break;
    }
  }
}


void deteksiK2Inverse() {
  sp_kompas = compassFront[1] - 5;
  readIRRange_6();
  while (IRRangeVal_6 >= 8) {
    navigasilurus(false, 4);
    command("kiribatu", 27, false);
    vTaskDelay(40 / portTICK_PERIOD_MS);
    readIRRange_6();
    DEBUG_SERIAL.print("IR KANAN : ");
    DEBUG_SERIAL.println(IRRangeVal_2);
  }
  readIRRange_6();
  while (IRRangeVal_6 <= 14) {
    navigasilurus(true, 4);
    command("kananbatu", 26, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    readIRRange_6();
    DEBUG_SERIAL.print("IR KANAN : ");
    DEBUG_SERIAL.println(IRRangeVal_2);
  }
  compassStart = 345;
  Baca_kompas();
  while (abs(compassOffset) >= 10) {
    if (compassOffset < 0) {
      command("rotateRightStart", 14, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else if (compassOffset > 0) {
      command("rotateLeftStart", 15, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    Baca_kompas();
  }

  command("taruhK1Inverse", 25, true);
  command("kosong", 35, false);
  vTaskDelay(100 / portTICK_PERIOD_MS);

  compassStart = compassFront[1] - 3; //?????
  Baca_kompas();
  while (abs(compassOffset) >= 10) {
    if (compassOffset < 0) {
      command("rotateRightStart", 14, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else if (compassOffset > 0) {
      command("rotateLeftStart", 15, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    Baca_kompas();
  }
  //======Taruh Korban 1 Inverse Arena===========//
  //=============Menuju Korban 2 Inverse Arena===========//
  sp_kompas = compassFront[1] - 5;
  readIRRange_6();
  while (IRRangeVal_6 < 22) {
    navigasilurus(true, 4);
    command("kananbatu", 26, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_6();
    DEBUG_SERIAL.print("IR KIRI : ");
    DEBUG_SERIAL.println(IRRangeVal_6);
  }

  readIRRange_0();
  while (IRRangeVal_0 >= 13) {
    for (int i = 0; i <= 3; i++) {
      navigasilurus(false, 4);
      command("majuserong", 21, true);
    }
    command("kosong", 35, false);
    vTaskDelay(30 / portTICK_PERIOD_MS); //30
    for (int i = 0; i <= 2; i++) {
      navigasilurus(true, 4);
      command("kananserong", 26, true);
    }
    command("kosong", 35, false);
    vTaskDelay(30 / portTICK_PERIOD_MS); //30
    readIRRange_0();
  }

  readIRRange_2();
  readIRRange_6();
  while (IRRangeVal_6 <= 58 && IRRangeVal_2 >= 44) {
    pict_x = 0;
    area = 0;
    navigasilurus(true, 4);
    command("kananbatu", 26, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_2();
    readIRRange_6();
  }
  //=============Menuju Korban 2 Inverse Arena===========//
  //=============Rotate Korban 2 Inverse==========//
  compassStart = 284;
  Baca_kompas();
  DEBUG_SERIAL.print("Arah : ");
  DEBUG_SERIAL.println(arah);
  DEBUG_SERIAL.print("Offset Awal: ");
  DEBUG_SERIAL.println(compassOffset);
  while (abs(compassOffset) >= 8) {
    DEBUG_SERIAL.println("while rotate K2");
    if (compassOffset < 0) {
      command("rotRightBatu", 47, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      DEBUG_SERIAL.print("Offset kanan : ");
      DEBUG_SERIAL.println(compassOffset);
    }
    else if (compassOffset > 0) {
      command("rotLeftBatu", 48, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      DEBUG_SERIAL.print("Offset kiri : ");
      DEBUG_SERIAL.println(compassOffset);
    }
    Baca_kompas();
  }
  readIRRange_4();
  while (IRRangeVal_4 <= 11) {
    DEBUG_SERIAL.println("while baca belakang");
    command("maju", 29, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_4();
  }
  vTaskDelay(400 / portTICK_PERIOD_MS);
  command("turun_capit", 11, true);
  command("kosong", 35, false);
  vTaskDelay(1100 / portTICK_PERIOD_MS);
  //=============Rotate Korban 2==========//
  //=============Deteksi Korban 2=========//
  pict_x = 0;
  area = 0;
  compassStart = 284;
  while (1) {
    DEBUG_SERIAL.println("while K2");
    Baca_kompas();
    vTaskDelay(30 / portTICK_PERIOD_MS);
    read_maix();
    vTaskDelay(52 / portTICK_PERIOD_MS);
    if (abs(compassOffset) >= 15 ) {
      if (compassOffset < 0) {
        command("rotateRightKelereng", 36, false);
        vTaskDelay(25 / portTICK_PERIOD_MS);
      }
      else if (compassOffset > 0) {
        command("rotateLeftKelereng", 37, false);
        vTaskDelay(25 / portTICK_PERIOD_MS);
      }
    }

    else if (pict_x < 160 - 10) {     //orang di sebelah kiri
      command("geser_kiri_dikit", 32, false);
      vTaskDelay(25 / portTICK_PERIOD_MS);
    }
    else if (pict_x > 160 + 14) {//orang di sebelah kanan
      command("geser_kanan_dikit", 31, false);
      vTaskDelay(25 / portTICK_PERIOD_MS);
    }
    else if (area < 10600) { //orang di tengah tapi jauh //awal 10400
      command("maju_dikit", 29, false);
      vTaskDelay(30 / portTICK_PERIOD_MS);

    }//kalo mau tambahin pke area bisa buat else if baru
    else if (area > 10400 + 3000) { //1700
      command("mundur_dikit", 30, false);
      vTaskDelay(30 / portTICK_PERIOD_MS);
    }
    else {
      command("grabK2", 23, true);
      vTaskDelay(10 / portTICK_PERIOD_MS);
      break;
    }
  }
  //=============Deteksi Korban 2 Inverse=========//
  command("kosong", 35, false);
  //=============Rotate Korban 2=========//
  compassStart = compassFront[2] - 10;
  Baca_kompas();
  DEBUG_SERIAL.print("Arah : ");
  DEBUG_SERIAL.println(arah);
  DEBUG_SERIAL.print("Offset Awal: ");
  DEBUG_SERIAL.println(compassOffset);
  while (abs(compassOffset) >= 10) {
    DEBUG_SERIAL.println("while rotate K2");
    if (compassOffset < 0) {
      command("rotRightBatu", 14, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      DEBUG_SERIAL.print("Offset kanan : ");
      DEBUG_SERIAL.println(compassOffset);
    }
    else if (compassOffset > 0) {
      command("rotLeftBatu", 15, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      DEBUG_SERIAL.print("Offset kiri : ");
      DEBUG_SERIAL.println(compassOffset);
    }
    Baca_kompas();
  }
  //=============Rotate Korban 2=========//
  //=============Safety Zone 2===========//
  sp_kompas = compassFront[2] - 12;
  while (1) {
    readIRRange_6();
    readIRRange_0();
    readIRRange_4();
    if (IRRangeVal_6 >= 10) {
      navigasilurus(false, 4);
      command("kiribatu", 27, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else if (IRRangeVal_0 > 27 && IRRangeVal_4 < 76) {
      navigasilurus(false, 4);
      command("majubatu", 21, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else {
      vTaskDelay(100 / portTICK_PERIOD_MS);
      command("taruhkorban", 25, true);
      break;
    }
  }
  //=============Safety Zone 2===========//
  //====================================//
  command("kosong", 35, false);
  vTaskDelay(300 / portTICK_PERIOD_MS);
  //===================================//

  //////////Menuju Tangga atau Korban 3/4////////////////////
  compassStart = compassFront[3] - 5;
  Baca_kompas();
  while (abs(compassOffset) >= 10) {
    if (compassOffset < 0) {
      command("rotRightBatu", 47, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else if (compassOffset > 0) {
      command("rotLeftBatu", 48, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    Baca_kompas();
  }
  sp_kompas = compassFront[3] - 5;
  readIRRange_4();
  while (IRRangeVal_4 <= 19) {
    navigasilurus(false, 4);
    command("majubatu", 21, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_4();
  }

  readIRRange_6();
  while (IRRangeVal_6 >= 15) {
    navigasilurus(false, 4);
    command("geserkiri", 27, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_6();
  }

  readIRRange_4();
  while (IRRangeVal_4 <= 69) {
    navigasilurus(false, 4);
    command("maju", 21, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_4();
  }

  Baca_kompas();
  DEBUG_SERIAL.println("KIRI PECAH 2");
  DEBUG_SERIAL.print("Arah : ");
  DEBUG_SERIAL.println(arah);
  sp_kompas = compassFront[3] - 5;
  readIRRange_2();
  while (IRRangeVal_2 >= 6) {
    navigasilurus(true, 3.5);
    command("kanancepat", 56, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_2();
  }

  height = -88;
  height2 = -88;
  command("standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(300 / portTICK_PERIOD_MS);

  compassStart = compassFront[3] - 5;
  Baca_kompas();
  while (abs(compassOffset) >= 14 ) {
    height = -88;
    height2 = -88;
    if (compassOffset < 0) {
      command("rotateRightPecah", 39, false);
    }
    else if (compassOffset > 0) {
      command("rotateLeftPecah", 40, false);
    }
    Baca_kompas();
  }
  //////////////////////////////////////Deteksi Korban 4////////////////////////////////
  DEBUG_SERIAL.print(F("PECAH 2"));
  readIRRange_0();
  readIRRange_4();
  DEBUG_SERIAL.print(F("IR DEPAN: "));
  DEBUG_SERIAL.print(IRRangeVal_0);
  DEBUG_SERIAL.print(F("IR BELAKANG: "));
  DEBUG_SERIAL.print(IRRangeVal_4);
  sp_kompas = compassFront[3] - 22;      //Acuan maju pecah 2 berbeda di Inverse maupun non, lebih deket ke tembok
  height = -88;
  height2 = -88;
  while (IRRangeVal_0 > 19 && IRRangeVal_4 < 102) {  //IRRangeVal_0 > 18 && IRRangeVal_4 < 102
    navigasilurus(false, 4);
    command("majupecah", 4, false);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    readIRRange_0();
    readIRRange_4();
  }
  compassStart = compassFront[3] - 5;
  readIRRange_2();
  readIRRange_6();
  while (IRRangeVal_6 > 22 && IRRangeVal_2 < 38 ) {
    navigasilurus(false, 4);
    command("kiribatu", 27, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_2();
    readIRRange_6();
  }
  //=============Gerakan Naik Tangga===============//
  readPitch();
  while (pitch <= 12) { //11
    compassStart = compassFront[3] - 5;
    Baca_kompas();
    if (abs(compassOffset) >= 20) {
      if (compassOffset < 0) {
        command("rotRightBatu", 47, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kanan : ");
        DEBUG_SERIAL.println(compassOffset);
      }
      else if (compassOffset > 0) {
        command("rotLeftBatu", 48, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kiri : ");
        DEBUG_SERIAL.println(compassOffset);
      }
    }
    else {
      height = -85;
      height2 = -85;
      command("TransisiTangga1", 44, false);
      readPitch();
    }
  }

  command("Standby", 57, true);
  command("kosong", 35, false);
  vTaskDelay(50 / portTICK_PERIOD_MS);
  command("StandbyTransisi1", 49, true);
  command("kosong", 35, false);
  vTaskDelay(50 / portTICK_PERIOD_MS);

  while (tangga) {
    height = -85;
    height2 = -90;
    readPitch();
    if (pitch > 28) {
      tangga = false;
    }
    else {
      command("NaikTangga", 45, false);
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }

  command("StandbyTransisi2", 50, true);
  command("kosong", 35, false);
  vTaskDelay(50 / portTICK_PERIOD_MS);

  while (1) {
    height = -85;
    height2 = -90;
    command("NaikTanggaFix", 58, false);
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}
