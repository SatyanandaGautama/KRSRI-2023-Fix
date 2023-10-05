void standbyTransisi1() { //dgn standby
  float FRcx = 202;// to 201
  float FRfm = 155;//to 165
  float FRtb = 245;
  float FLcx = 86;// to 85
  float FLfm = 159;//to 169
  float FLtb = 249.5;
  float BRcx = 112;//to 123
  float BRfm = 150;//to 110
  float BRtb = 226;//to 173
  float BLcx = 183;//to 198
  float BLfm = 159;//to 106
  float BLtb = 232;//to 189
  for (int i = 0; i <= 49; i++) {
    kanan_atas(FRcx, FRfm, 245);
    kiri_atas(FLcx, FLfm, 249.5);
    kiri_bawah(BLcx, BLfm, BLtb);
    kanan_bawah(BRcx, BRfm, BRtb);
    FRcx += 0.02;
    FRfm += 0.2;
    FLcx -= 0.02;
    FLfm += 0.2;
    BRcx += 0.22;
    BLcx += 0.3;
    BLfm -= 1.06;
    BLtb -= 0.86;
    BRcx += 0.2;
    BRfm -= 0.8;
    BRtb -= 1.06;
    delay(10);
  }
}

void standbyTransisi2() { //tanpa standby
  float FRcx = 204;// to 237
  float FRfm = 167;//to 175
  float FRtb = 239.5;//to 256
  float BLcx = 193;//to 157
  float BLfm = 112;//to 102
  float BLtb = 193;//to 160
  float FLcx = 87;// to 86
  float FLfm = 169;//to 185
  float FLtb = 250.5;//to 249
  float BRcx = 123;//to 116
  float BRfm = 115;//to 102
  float BRtb = 179;//to 185
  for (int i = 0; i <= 49; i++) {
    kanan_atas(FRcx, FRfm, FRtb);
    kiri_atas(FLcx, FLfm, FLtb);
    kiri_bawah(BLcx, BLfm, BLtb);
    kanan_bawah(BRcx, BRfm, BRtb);
    FRcx += 0.66;
    FRfm += 0.16;
    FRtb += 0.33;
    BLcx -= 0.72;
    BLfm -= 0.2;
    BLtb -= 0.66;
    FLfm += 0.32;
    FLtb += 0.02;
    BRcx -= 0.14;
    BRfm -= 0.26;
    BRtb += 0.12;
    delay(8);
  }
}

//================IK Transisi Tangga 1======================//
void FR4(float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 22; //11

  if (angle2 > 195) sdtcoxa = angle2 + lebar;
  if (angle2 == 195) sdtcoxa = angle2;
  if (angle2 < 195) sdtcoxa = angle2 - lebar;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 149; //136
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void FL4(float x, float y, float h, float lebar) { //105
  z = height + h;
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  angle2 = round(angle1 - legoffset[1]) - 4; //13

  if (arahgerak == true) { //Maju & Mundur
    if (angle2 > 105) sdtcoxa = angle2 - lebar;
    if (angle2 < 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }
  if (arahgerak == false) { //Geser Kanan & Kiri
    if (angle2 > 105) sdtcoxa = angle2 + lebar;
    if (angle2 < 105) sdtcoxa = angle2 - lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 76; //71

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 153.5; //146
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BL4(float x, float y, float h, float lebar) { //195
  z = height2 + h;
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  angle2 = round(angle1 - legoffset[2]) + 3; //10

  if (angle2 < 195) sdtcoxa = angle2 + lebar;
  if (angle2 > 195) sdtcoxa = angle2 - lebar;
  if (angle2 == 195) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));

  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 68; //72

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 136; //141
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BR4(float x, float y, float h, float lebar) { //105
  z = height2 + h;
  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
  angle2 = round(angle1 - legoffset[3]) + 22; //15

  if (arahgerak == true) { //maju mundur
    if (angle2 < 105) sdtcoxa = angle2 - lebar;
    if (angle2 > 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }
  if (arahgerak == false) { //geser kanan kiri
    if (angle2 > 105) sdtcoxa = angle2 - lebar;
    if (angle2 < 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }

  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
  // if (angle2 == 105) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 67; //71

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 130; //138
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}
//================IK Transisi Tangga 1======================//


//================IK Transisi Tangga 2======================//
void FR6 (float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 24; //6 //11  //24 //asli 27

  if (angle2 > 195) sdtcoxa = angle2 + lebar;
  if (angle2 == 195) sdtcoxa = angle2;
  if (angle2 < 195) sdtcoxa = angle2 - lebar;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 82; //97

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 150.5; //150
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void FL6(float x, float y, float h, float lebar) { //105
  z = height + h;
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  angle2 = round(angle1 - legoffset[1]) - 4; //18 //3 //asli 3

  if (arahgerak == true) { //Maju & Mundur
    if (angle2 > 105) sdtcoxa = angle2 - lebar;
    if (angle2 < 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }
  if (arahgerak == false) { //Geser Kanan & Kiri
    if (angle2 > 105) sdtcoxa = angle2 + lebar;
    if (angle2 < 105) sdtcoxa = angle2 - lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 86; //101

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 154; //153
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BL6 (float x, float y, float h, float lebar) { //195
  z = height2 + h;
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  angle2 = round(angle1 - legoffset[2]) - 7; //5

  if (angle2 < 195) sdtcoxa = angle2 + lebar;
  if (angle2 > 195) sdtcoxa = angle2 - lebar;
  if (angle2 == 195) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));

  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 34; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 91; //149 //89
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}
void BR6 (float x, float y, float h, float lebar) { //105
  z = height2 + h;
  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
  angle2 = round(angle1 - legoffset[3]) + 32; //20

  if (arahgerak == true) { //maju mundur
    if (angle2 < 105) sdtcoxa = angle2 - lebar;
    if (angle2 > 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }
  if (arahgerak == false) { //geser kanan kiri
    if (angle2 > 105) sdtcoxa = angle2 - lebar;
    if (angle2 < 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }

  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
  // if (angle2 == 105) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 31; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 89; //138 //80
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}
//====================IK Transisi Tangga 2====================//
//================IK Naik Tangga======================//
void FR5(float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 32; //6 //11  //29

  if (angle2 > 195) sdtcoxa = angle2 + lebar;
  if (angle2 == 195) sdtcoxa = angle2;
  if (angle2 < 195) sdtcoxa = angle2 - lebar;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 98; //97

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 153; //150.5
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  //   Serial.println("FRONT RIGHT :");
  //   Serial.print("CX :");
  //   Serial.println(sdtcoxa);
  //   Serial.print("FM :");
  //   Serial.println(sdtfemur);
  //   Serial.print("TB :");
  //   Serial.println(sdttibia);
}

void FL5(float x, float y, float h, float lebar) { //105
  z = height + h;
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  angle2 = round(angle1 - legoffset[1]) - 5; //18 //3 //4

  if (arahgerak == true) { //Maju & Mundur
    if (angle2 > 105) sdtcoxa = angle2 - lebar;
    if (angle2 < 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }
  if (arahgerak == false) { //Geser Kanan & Kiri
    if (angle2 > 105) sdtcoxa = angle2 + lebar;
    if (angle2 < 105) sdtcoxa = angle2 - lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 101; //101

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 154; //154
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  //   Serial.println("FRONT LEFT :");
  //   Serial.print("CX :");
  //   Serial.println(sdtcoxa);
  //   Serial.print("FM :");
  //   Serial.println(sdtfemur);
  //   Serial.print("TB :");
  //   Serial.println(sdttibia);
}

void BL5(float x, float y, float h, float lebar) { //195
  z = height2 + h;
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  angle2 = round(angle1 - legoffset[2]) - 7; //5

  if (angle2 < 195) sdtcoxa = angle2 + lebar;
  if (angle2 > 195) sdtcoxa = angle2 - lebar;
  if (angle2 == 195) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));

  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 19; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 91; //149 //89
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  //   Serial.println("BACK LEFT :");
  //   Serial.print("CX :");
  //   Serial.println(sdtcoxa);
  //   Serial.print("FM :");
  //   Serial.println(sdtfemur);
  //   Serial.print("TB :");
  //   Serial.println(sdttibia);
}

void BR5(float x, float y, float h, float lebar) { //105
  z = height2 + h;
  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
  angle2 = round(angle1 - legoffset[3]) + 27; //20

  if (arahgerak == true) { //maju mundur
    if (angle2 < 105) sdtcoxa = angle2 - lebar;
    if (angle2 > 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }
  if (arahgerak == false) { //geser kanan kiri
    if (angle2 > 105) sdtcoxa = angle2 - lebar;
    if (angle2 < 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }

  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
  // if (angle2 == 105) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 19; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 88; //138 //80
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  //   Serial.println("BACK RIGHT :");
  //   Serial.print("CX :");
  //   Serial.println(sdtcoxa);
  //   Serial.print("FM :");
  //   Serial.println(sdtfemur);
  //   Serial.print("TB :");
  //   Serial.println(sdttibia);
}
//====================IK Naik Tangga====================//


void naiktanggaFix3() {
  FR5(20.00, 55.00, 0.00, 0);
  BL5(-100.00, -55.00, 0.00, 0);
  FL5(-57.69, 55.00, 0.00, 0);
  BR5(52.31, -55.00, 0.00, 0);
  delay(dt);

  FR5(21.96, 55.00, 10.80, 0);
  BL5(-97.48, -55.00, 18.00, 0);
  FL5(-57.54, 55.00, 0.00, 0);
  BR5(52.46, -55.00, 0.00, 0);
  delay(dt);


  FR5(27.28, 55.00, 19.20, 0);
  BL5(-90.64, -55.00, 32.00, 0);
  FL5(-57.13, 55.00, 0.00, 0);
  BR5(52.87, -55.00, 0.00, 0);
  delay(dt);

  FR5(35.12, 55.00, 25.20, 0);
  BL5(-80.56, -55.00, 42.00, 0);
  FL5(-56.53, 55.00, 0.00, 0);
  BR5(53.47, -55.00, 0.00, 0);
  delay(dt);

  FR5(44.64, 55.00, 28.80, 0);
  BL5(-68.32, -55.00, 48.00, 0);
  FL5(-55.80, 55.00, 0.00, 0);
  BR5(54.20, -55.00, 0.00, 0);
  delay(dt);

  FR5(55.00, 55.00, 30.00, 0);
  BL5(-55.00, -55.00, 50.00, 0);
  FL5(-55.00, 55.00, 0.00, 0);
  BR5(55.00, -55.00, 0.00, 0);
  delay(dt);

  FR5(65.36, 55.00, 28.80, 0);
  BL5(-41.68, -55.00, 48.00, 0);
  FL5(-54.20, 55.00, 0.00, 0);
  BR5(55.80, -55.00, 0.00, 0);
  delay(dt);

  FR5(74.88, 55.00, 25.20, 0);
  BL5(-29.44, -55.00, 42.00, 0);
  FL5(-53.47, 55.00, 0.00, 0);
  BR5(56.53, -55.00, 0.00, 0);
  delay(dt);

  FR5(82.72, 55.00, 19.20, 0);
  BL5(-19.36, -55.00, 32.00, 0);
  FL5(-52.87, 55.00, 0.00, 0);
  BR5(57.13, -55.00, 0.00, 0);
  delay(dt);

  FR5(88.04, 55.00, 10.80, 0);
  BL5(-12.52, -55.00, 18.00, 0);
  FL5(-52.46, 55.00, 0.00, 0);
  BR5(57.54, -55.00, 0.00, 0);
  delay(dt);

  FR5(89, 55, 6.29, 0);
  BL5(-11.5, -55, 15.85, 0);
  FL5(-52.40, 55, 0, 0);
  BR5(57.6, -55, 0, 0);
  delay(dt);

  FR5(89.5, 55, 2.3, 0);
  BL5(-10.5, -55, 7.3, 0);
  FL5(-52.35, 55, 0, 0);
  BR5(57.65, -55, 0, 0);
  delay(dt);

  FR5(90.00, 55.00, 0.00, 0);
  BL5(-10.00, -55.00, 0.00, 0);
  FL5(-52.31, 55.00, 0.00, 0);
  BR5(57.69, -55.00, 0.00, 0);
  delay(dt);

  FR5(89.93, 55.00, 0.00, 0);
  BL5(-10.10, -55.00, 0.00, 0);
  FL5(-52.24, 55.00, 0.00, 0);
  BR5(57.79, -55.00, 0.00, 0);
  delay(dt);

  FR5(89.71, 55.00, 0.00, 0);
  BL5(-10.38, -55.00, 0.00, 0);
  FL5(-52.02, 55.00, 0.00, 0);
  BR5(58.07, -55.00, 0.00, 0);
  delay(dt);

  FR5(89.36, 55.00, 0.00, 0);
  BL5(-10.83, -55.00, 0.00, 0);
  FL5(-51.67, 55.00, 0.00, 0);
  BR5(58.52, -55.00, 0.00, 0);
  delay(dt);

  FR5(88.89, 55.00, 0.00, 0);
  BL5(-11.45, -55.00, 0.00, 0);
  FL5(-51.20, 55.00, 0.00, 0);
  BR5(59.14, -55.00, 0.00, 0);
  delay(dt);

  FR5(88.30, 55.00, 0.00, 0);
  BL5(-12.22, -55.00, 0.00, 0);
  FL5(-50.61, 55.00, 0.00, 0);
  BR5(59.91, -55.00, 0.00, 0);
  delay(dt);

  FR5(87.61, 55.00, 0.00, 0);
  BL5(-13.13, -55.00, 0.00, 0);
  FL5(-49.92, 55.00, 0.00, 0);
  BR5(60.82, -55.00, 0.00, 0);
  delay(dt);


  FR5(86.81, 55.00, 0.00, 0);
  BL5(-14.18, -55.00, 0.00, 0);
  FL5(-49.12, 55.00, 0.00, 0);
  BR5(61.87, -55.00, 0.00, 0);
  delay(dt);


  FR5(85.92, 55.00, 0.00, 0);
  BL5(-15.34, -55.00, 0.00, 0);
  FL5(-48.23, 55.00, 0.00, 0);
  BR5(63.03, -55.00, 0.00, 0);
  delay(dt);


  FR5(84.95, 55.00, 0.00, 0);
  BL5(-16.61, -55.00, 0.00, 0);
  FL5(-47.26, 55.00, 0.00, 0);
  BR5(64.30, -55.00, 0.00, 0);
  delay(dt);


  FR5(83.91, 55.00, 0.00, 0);
  BL5(-17.98, -55.00, 0.00, 0);
  FL5(-46.22, 55.00, 0.00, 0);
  BR5(65.67, -55.00, 0.00, 0);
  delay(dt);


  FR5(82.79, 55.00, 0.00, 0);
  BL5(-19.44, -55.00, 0.00, 0);
  FL5(-45.10, 55.00, 0.00, 0);
  BR5(67.13, -55.00, 0.00, 0);
  delay(dt);


  FR5(81.62, 55.00, 0.00, 0);
  BL5(-20.97, -55.00, 0.00, 0);
  FL5(-43.93, 55.00, 0.00, 0);
  BR5(68.66, -55.00, 0.00, 0);
  delay(dt);


  FR5(80.40, 55.00, 0.00, 0);
  BL5(-22.57, -55.00, 0.00, 0);
  FL5(-42.71, 55.00, 0.00, 0);
  BR5(70.26, -55.00, 0.00, 0);
  delay(dt);


  FR5(79.14, 55.00, 0.00, 0);
  BL5(-24.22, -55.00, 0.00, 0);
  FL5(-41.45, 55.00, 0.00, 0);
  BR5(71.91, -55.00, 0.00, 0);
  delay(dt);


  FR5(77.85, 55.00, 0.00, 0);
  BL5(-25.92, -55.00, 0.00, 0);
  FL5(-40.16, 55.00, 0.00, 0);
  BR5(73.61, -55.00, 0.00, 0);
  delay(dt);


  FR5(76.53, 55.00, 0.00, 0);
  BL5(-27.64, -55.00, 0.00, 0);
  FL5(-38.84, 55.00, 0.00, 0);
  BR5(75.33, -55.00, 0.00, 0);
  delay(dt);


  FR5(75.19, 55.00, 0.00, 0);
  BL5(-29.39, -55.00, 0.00, 0);
  FL5(-37.50, 55.00, 0.00, 0);
  BR5(77.08, -55.00, 0.00, 0);
  delay(dt);


  FR5(73.84, 55.00, 0.00, 0);
  BL5(-31.16, -55.00, 0.00, 0);
  FL5(-36.15, 55.00, 0.00, 0);
  BR5(78.85, -55.00, 0.00, 0);
  delay(dt);


  FR5(72.50, 55.00, 0.00, 0);
  BL5(-32.92, -55.00, 0.00, 0);
  FL5(-34.81, 55.00, 0.00, 0);
  BR5(80.61, -55.00, 0.00, 0);
  delay(dt);


  FR5(71.16, 55.00, 0.00, 0);
  BL5(-34.67, -55.00, 0.00, 0);
  FL5(-33.47, 55.00, 0.00, 0);
  BR5(82.36, -55.00, 0.00, 0);
  delay(dt);


  FR5(69.84, 55.00, 0.00, 0);
  BL5(-36.39, -55.00, 0.00, 0);
  FL5(-32.15, 55.00, 0.00, 0);
  BR5(84.08, -55.00, 0.00, 0);
  delay(dt);


  FR5(68.55, 55.00, 0.00, 0);
  BL5(-38.09, -55.00, 0.00, 0);
  FL5(-30.86, 55.00, 0.00, 0);
  BR5(85.78, -55.00, 0.00, 0);
  delay(dt);


  FR5(67.29, 55.00, 0.00, 0);
  BL5(-39.74, -55.00, 0.00, 0);
  FL5(-29.60, 55.00, 0.00, 0);
  BR5(87.43, -55.00, 0.00, 0);
  delay(dt);


  FR5(66.07, 55.00, 0.00, 0);
  BL5(-41.34, -55.00, 0.00, 0);
  FL5(-28.38, 55.00, 0.00, 0);
  BR5(89.03, -55.00, 0.00, 0);
  delay(dt);


  FR5(64.90, 55.00, 0.00, 0);
  BL5(-42.87, -55.00, 0.00, 0);
  FL5(-27.21, 55.00, 0.00, 0);
  BR5(90.56, -55.00, 0.00, 0);
  delay(dt);


  FR5(63.78, 55.00, 0.00, 0);
  BL5(-44.33, -55.00, 0.00, 0);
  FL5(-26.09, 55.00, 0.00, 0);
  BR5(92.02, -55.00, 0.00, 0);
  delay(dt);


  FR5(62.74, 55.00, 0.00, 0);
  BL5(-45.70, -55.00, 0.00, 0);
  FL5(-25.05, 55.00, 0.00, 0);
  BR5(93.39, -55.00, 0.00, 0);
  delay(dt);


  FR5(61.77, 55.00, 0.00, 0);
  BL5(-46.97, -55.00, 0.00, 0);
  FL5(-24.08, 55.00, 0.00, 0);
  BR5(94.66, -55.00, 0.00, 0);
  delay(dt);


  FR5(60.88, 55.00, 0.00, 0);
  BL5(-48.13, -55.00, 0.00, 0);
  FL5(-23.19, 55.00, 0.00, 0);
  BR5(95.82, -55.00, 0.00, 0);
  delay(dt);


  FR5(60.08, 55.00, 0.00, 0);
  BL5(-49.18, -55.00, 0.00, 0);
  FL5(-22.39, 55.00, 0.00, 0);
  BR5(96.87, -55.00, 0.00, 0);
  delay(dt);


  FR5(59.39, 55.00, 0.00, 0);
  BL5(-50.09, -55.00, 0.00, 0);
  FL5(-21.70, 55.00, 0.00, 0);
  BR5(97.78, -55.00, 0.00, 0);
  delay(dt);


  FR5(58.80, 55.00, 0.00, 0);
  BL5(-50.86, -55.00, 0.00, 0);
  FL5(-21.11, 55.00, 0.00, 0);
  BR5(98.55, -55.00, 0.00, 0);
  delay(dt);


  FR5(58.33, 55.00, 0.00, 0);
  BL5(-51.48, -55.00, 0.00, 0);
  FL5(-20.64, 55.00, 0.00, 0);
  BR5(99.17, -55.00, 0.00, 0);
  delay(dt);


  FR5(57.98, 55.00, 0.00, 0);
  BL5(-51.93, -55.00, 0.00, 0);
  FL5(-20.29, 55.00, 0.00, 0);
  BR5(99.62, -55.00, 0.00, 0);
  delay(dt);


  FR5(57.76, 55.00, 0.00, 0);
  BL5(-52.21, -55.00, 0.00, 0);
  FL5(-20.07, 55.00, 0.00, 0);
  BR5(99.90, -55.00, 0.00, 0);
  delay(dt);


  FR5(57.69, 55.00, 0.00, 0);
  BL5(-52.31, -55.00, 0.00, 0);
  FL5(-20.00, 55.00, 0.00, 0);
  BR5(100.00, -55.00, 0.00, 0);
  delay(dt);

  FR5(57.54, 55.00, 0.00, 0);
  BL5(-52.46, -55.00, 0.00, 0);
  FL5(-21.96, 55.00, 10.80, 0);
  BR5(97.48, -55.00, 18.00, 0);
  delay(dt);

  FR5(57.13, 55.00, 0, 0);
  BL5(-52.87, -55.00, 0, 0);
  FL5(-27.28, 55.00, 19.2, 0);
  BR5(90.64, -55.00, 32, 0);
  delay(dt);


  FR5(56.53, 55.00, 0, 0);
  BL5(-53.47, -55.00, 0, 0);
  FL5(-35.12, 55.00, 25.2, 0);
  BR5(80.56, -55.00, 42, 0);
  delay(dt);


  FR5(55.80, 55.00, 0, 0);
  BL5(-54.20, -55.00, 0, 0);
  FL5(-44.64, 55.00, 28.80, 0);
  BR5(68.32, -55.00, 48, 0);
  delay(dt);


  FR5(55.00, 55.00, 0, 0);
  BL5(-55.00, -55.00, 0, 0);
  FL5(-55.00, 55.00, 30, 0);
  BR5(55.00, -55.00, 50, 0);
  delay(dt);


  FR5(54.20, 55.00, 0, 0);
  BL5(-55.80, -55.00, 0, 0);
  FL5(-65.36, 55.00, 28.80, 0);
  BR5(41.68, -55.00, 48.00, 0);
  delay(dt);


  FR5(53.47, 55.00, 0, 0);
  BL5(-56.53, -55.00, 0, 0);
  FL5(-74.88, 55.00, 25.2, 0);
  BR5(29.44, -55.00, 42, 0);
  delay(dt);

  FR5(52.87, 55.00, 0, 0);
  BL5(-57.13, -55.00, 0, 0);
  FL5(-82.72, 55.00, 19.20, 0);
  BR5(19.36, -55.00, 32.00, 0);
  delay(dt);

  FR5(52.46, 55.00, 0, 0);
  BL5(-57.54, -55.00, 0, 0);
  FL5(-88.04, 55.00, 10.80, 0);
  BR5(12.52, -55.00, 18.00, 0);
  delay(dt);

  FR5(52.4, 55, 0, 0);
  BL5(-57.6, -55, 0, 0);
  FL5(-89, 55, 6.29, 0);
  BR5(11.5, -55, 15.85, 0);
  delay(dt);

  FR5(52.35, 55, 0, 0);
  BL5(-57.65, -55, 0, 0);
  FL5(-89.5, 55, 2.3, 0);
  BR5(10.5, -55, 7.3, 0);
  delay(dt);

  FR5(52.31, 55.00, 0.00, 0);
  BL5(-57.69, -55.00, 0.00, 0);
  FL5(-90.00, 55.00, 0.00, 0);
  BR5(10.00, -55.00, 0.00, 0);
  delay(dt);

  FR5(52.24, 55.00, 0.00, 0);
  BL5(-57.79, -55.00, 0.00, 0);
  FL5(-89.93, 55.00, 0.00, 0);
  BR5(10.10, -55.00, 0.00, 0);
  delay(dt);

  FR5(52.02, 55.00, 0.00, 0);
  BL5(-58.07, -55.00, 0.00, 0);
  FL5(-89.71, 55.00, 0.00, 0);
  BR5(10.38, -55.00, 0.00, 0);
  delay(dt);


  FR5(51.67, 55.00, 0.00, 0);
  BL5(-58.52, -55.00, 0.00, 0);
  FL5(-89.36, 55.00, 0.00, 0);
  BR5(10.83, -55.00, 0.00, 0);
  delay(dt);


  FR5(51.20, 55.00, 0.00, 0);
  BL5(-59.14, -55.00, 0.00, 0);
  FL5(-88.89, 55.00, 0.00, 0);
  BR5(11.45, -55.00, 0.00, 0);
  delay(dt);


  FR5(50.61, 55.00, 0.00, 0);
  BL5(-59.91, -55.00, 0.00, 0);
  FL5(-88.30, 55.00, 0.00, 0);
  BR5(12.22, -55.00, 0.00, 0);
  delay(dt);


  FR5(49.92, 55.00, 0.00, 0);
  BL5(-60.82, -55.00, 0.00, 0);
  FL5(-87.61, 55.00, 0.00, 0);
  BR5(13.13, -55.00, 0.00, 0);
  delay(dt);


  FR5(49.12, 55.00, 0.00, 0);
  BL5(-61.87, -55.00, 0.00, 0);
  FL5(-86.81, 55.00, 0.00, 0);
  BR5(14.18, -55.00, 0.00, 0);
  delay(dt);


  FR5(48.23, 55.00, 0.00, 0);
  BL5(-63.03, -55.00, 0.00, 0);
  FL5(-85.92, 55.00, 0.00, 0);
  BR5(15.34, -55.00, 0.00, 0);
  delay(dt);


  FR5(47.26, 55.00, 0.00, 0);
  BL5(-64.30, -55.00, 0.00, 0);
  FL5(-84.95, 55.00, 0.00, 0);
  BR5(16.61, -55.00, 0.00, 0);
  delay(dt);


  FR5(46.22, 55.00, 0.00, 0);
  BL5(-65.67, -55.00, 0.00, 0);
  FL5(-83.91, 55.00, 0.00, 0);
  BR5(17.98, -55.00, 0.00, 0);
  delay(dt);


  FR5(45.10, 55.00, 0.00, 0);
  BL5(-67.13, -55.00, 0.00, 0);
  FL5(-82.79, 55.00, 0.00, 0);
  BR5(19.44, -55.00, 0.00, 0);
  delay(dt);


  FR5(43.93, 55.00, 0.00, 0);
  BL5(-68.66, -55.00, 0.00, 0);
  FL5(-81.62, 55.00, 0.00, 0);
  BR5(20.97, -55.00, 0.00, 0);
  delay(dt);


  FR5(42.71, 55.00, 0.00, 0);
  BL5(-70.26, -55.00, 0.00, 0);
  FL5(-80.40, 55.00, 0.00, 0);
  BR5(22.57, -55.00, 0.00, 0);
  delay(dt);


  FR5(41.45, 55.00, 0.00, 0);
  BL5(-71.91, -55.00, 0.00, 0);
  FL5(-79.14, 55.00, 0.00, 0);
  BR5(24.22, -55.00, 0.00, 0);
  delay(dt);


  FR5(40.16, 55.00, 0.00, 0);
  BL5(-73.61, -55.00, 0.00, 0);
  FL5(-77.85, 55.00, 0.00, 0);
  BR5(25.92, -55.00, 0.00, 0);
  delay(dt);


  FR5(38.84, 55.00, 0.00, 0);
  BL5(-75.33, -55.00, 0.00, 0);
  FL5(-76.53, 55.00, 0.00, 0);
  BR5(27.64, -55.00, 0.00, 0);
  delay(dt);


  FR5(37.50, 55.00, 0.00, 0);
  BL5(-77.08, -55.00, 0.00, 0);
  FL5(-75.19, 55.00, 0.00, 0);
  BR5(29.39, -55.00, 0.00, 0);
  delay(dt);


  FR5(36.15, 55.00, 0.00, 0);
  BL5(-78.85, -55.00, 0.00, 0);
  FL5(-73.84, 55.00, 0.00, 0);
  BR5(31.16, -55.00, 0.00, 0);
  delay(dt);


  FR5(34.81, 55.00, 0.00, 0);
  BL5(-80.61, -55.00, 0.00, 0);
  FL5(-72.50, 55.00, 0.00, 0);
  BR5(32.92, -55.00, 0.00, 0);
  delay(dt);


  FR5(33.47, 55.00, 0.00, 0);
  BL5(-82.36, -55.00, 0.00, 0);
  FL5(-71.16, 55.00, 0.00, 0);
  BR5(34.67, -55.00, 0.00, 0);
  delay(dt);


  FR5(32.15, 55.00, 0.00, 0);
  BL5(-84.08, -55.00, 0.00, 0);
  FL5(-69.84, 55.00, 0.00, 0);
  BR5(36.39, -55.00, 0.00, 0);
  delay(dt);


  FR5(30.86, 55.00, 0.00, 0);
  BL5(-85.78, -55.00, 0.00, 0);
  FL5(-68.55, 55.00, 0.00, 0);
  BR5(38.09, -55.00, 0.00, 0);
  delay(dt);


  FR5(29.60, 55.00, 0.00, 0);
  BL5(-87.43, -55.00, 0.00, 0);
  FL5(-67.29, 55.00, 0.00, 0);
  BR5(39.74, -55.00, 0.00, 0);
  delay(dt);


  FR5(28.38, 55.00, 0.00, 0);
  BL5(-89.03, -55.00, 0.00, 0);
  FL5(-66.07, 55.00, 0.00, 0);
  BR5(41.34, -55.00, 0.00, 0);
  delay(dt);


  FR5(27.21, 55.00, 0.00, 0);
  BL5(-90.56, -55.00, 0.00, 0);
  FL5(-64.90, 55.00, 0.00, 0);
  BR5(42.87, -55.00, 0.00, 0);
  delay(dt);


  FR5(26.09, 55.00, 0.00, 0);
  BL5(-92.02, -55.00, 0.00, 0);
  FL5(-63.78, 55.00, 0.00, 0);
  BR5(44.33, -55.00, 0.00, 0);
  delay(dt);


  FR5(25.05, 55.00, 0.00, 0);
  BL5(-93.39, -55.00, 0.00, 0);
  FL5(-62.74, 55.00, 0.00, 0);
  BR5(45.70, -55.00, 0.00, 0);
  delay(dt);


  FR5(24.08, 55.00, 0.00, 0);
  BL5(-94.66, -55.00, 0.00, 0);
  FL5(-61.77, 55.00, 0.00, 0);
  BR5(46.97, -55.00, 0.00, 0);
  delay(dt);


  FR5(23.19, 55.00, 0.00, 0);
  BL5(-95.82, -55.00, 0.00, 0);
  FL5(-60.88, 55.00, 0.00, 0);
  BR5(48.13, -55.00, 0.00, 0);
  delay(dt);


  FR5(22.39, 55.00, 0.00, 0);
  BL5(-96.87, -55.00, 0.00, 0);
  FL5(-60.08, 55.00, 0.00, 0);
  BR5(49.18, -55.00, 0.00, 0);
  delay(dt);


  FR5(21.70, 55.00, 0.00, 0);
  BL5(-97.78, -55.00, 0.00, 0);
  FL5(-59.39, 55.00, 0.00, 0);
  BR5(50.09, -55.00, 0.00, 0);
  delay(dt);


  FR5(21.11, 55.00, 0.00, 0);
  BL5(-98.55, -55.00, 0.00, 0);
  FL5(-58.80, 55.00, 0.00, 0);
  BR5(50.86, -55.00, 0.00, 0);
  delay(dt);


  FR5(20.64, 55.00, 0.00, 0);
  BL5(-99.17, -55.00, 0.00, 0);
  FL5(-58.33, 55.00, 0.00, 0);
  BR5(51.48, -55.00, 0.00, 0);
  delay(dt);


  FR5(20.29, 55.00, 0.00, 0);
  BL5(-99.62, -55.00, 0.00, 0);
  FL5(-57.98, 55.00, 0.00, 0);
  BR5(51.93, -55.00, 0.00, 0);
  delay(dt);


  FR5(20.07, 55.00, 0.00, 0);
  BL5(-99.90, -55.00, 0.00, 0);
  FL5(-57.76, 55.00, 0.00, 0);
  BR5(52.21, -55.00, 0.00, 0);
  delay(dt);
}
