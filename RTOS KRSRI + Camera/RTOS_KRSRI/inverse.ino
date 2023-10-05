//================IK Rotate Naik Tangga======================//
void FRRot(float x, float y, float h, float sudut) {
  z = height + h;
  if (x >= 0 && y >= 0) {
    angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas(FR)
    angle2 = round(angle1 - legoffset[0]) + 26;  //asli 26
    //Batasi sudut offet
    if (sudut >= 8)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 8)sdtcoxa = 195; //Agar diam di tempat

    if (angle2 < 195)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 195)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 195)sdtcoxa = angle2;
  }

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 97; //97

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

void FLRot(float x, float y, float h, float sudut) { //105
  z = height + h;
  if (x < 0 && y >= 0) {
    angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas(FL)
    angle2 = round(angle1 - legoffset[1]) - 4;
    //Batasi sudut offet
    if (sudut >= 8)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 8)sdtcoxa = 105; //Agar diam di tempat

    if (angle2 < 105)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 105)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 105)sdtcoxa = angle2;
  }

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 101; //101

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 154.5; //153
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BLRot(float x, float y, float h, float sudut) { //195
  z = height2 + h;
  if (x < 0 && y < 0) {
    angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah(BL)
    angle2 = round(angle1 - legoffset[2]) - 7;
    //Batasi sudut offet
    if (sudut >= 8)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 8)sdtcoxa = 195; //Agar diam di tempat

    if (angle2 < 195)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 195)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 195)sdtcoxa = angle2;
  }

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
  // Serial.println("BACK LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BRRot(float x, float y, float h, float sudut) { //105
  z = height2 + h;
  if (x >= 0 && y < 0) {
    angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah(BR)
    angle2 = round(angle1 - legoffset[3]) + 32;
    //Batasi sudut offet
    if (sudut >= 8)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 8)sdtcoxa = 105; //Agar diam di tempat

    if (angle2 < 105)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 105)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 105)sdtcoxa = angle2;
  }

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 19; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 78; //138 //80
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}
//====================IK Rotate Naik Tangga====================//

void IKRot1(float x, float y, float h, float sudut) { //Default Gerakan Rotate 10 Derajat (Saat sudut = 0)
  //sdtrotate = (sudut - 10)/2;
  z = height + h;
  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 72 ;

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 144; //138

  if (x >= 0 && y >= 0) {
    angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas(FR)
    angle2 = round(angle1 - legoffset[0]) + 15;
    //Batasi sudut offet
    if (sudut >= 10)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 10)sdtcoxa = 195; //Agar diam di tempat

    if (angle2 < 195)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 195)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 195)sdtcoxa = angle2;
    kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  }

  if (x < 0 && y >= 0) {
    angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas(FL)
    angle2 = round(angle1 - legoffset[1]) + 15;
    //Batasi sudut offet
    if (sudut >= 10)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 10)sdtcoxa = 105; //Agar diam di tempat

    if (angle2 < 105)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 105)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 105)sdtcoxa = angle2;
    kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  }

  if (x < 0 && y < 0) {
    angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah(BL)
    angle2 = round(angle1 - legoffset[2]) + 15;
    //Batasi sudut offet
    if (sudut >= 10)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 10)sdtcoxa = 195; //Agar diam di tempat

    if (angle2 < 195)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 195)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 195)sdtcoxa = angle2;
    kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  }

  if (x >= 0 && y < 0) {
    angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah(BR)
    angle2 = round(angle1 - legoffset[3]) + 15;
    //Batasi sudut offet
    if (sudut >= 10)sdtrotate = (sudut - 10) / 2;
    else if (sudut < 10)sdtcoxa = 105; //Agar diam di tempat

    if (angle2 < 105)sdtcoxa = angle2 - sdtrotate;
    else if (angle2 > 105)sdtcoxa = angle2 + sdtrotate;
    else if (angle2 == 105)sdtcoxa = angle2;
    kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  }
}


void FR(float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 12; //11

  if (angle2 > 195) sdtcoxa = angle2 + lebar;
  if (angle2 == 195) sdtcoxa = angle2;
  if (angle2 < 195) sdtcoxa = angle2 - lebar;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //71

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 141; //139
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void FL (float x, float y, float h, float lebar) { //105
  z = height + h;
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  angle2 = round(angle1 - legoffset[1]) + 13; //18

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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //73

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 149; //146
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BL (float x, float y, float h, float lebar) { //195
  z = height2 + h;
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  angle2 = round(angle1 - legoffset[2]) + 10; //10

  if (angle2 < 195) sdtcoxa = angle2 + lebar;
  if (angle2 > 195) sdtcoxa = angle2 - lebar;
  if (angle2 == 195) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));

  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //72

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 145; //143
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BR (float x, float y, float h, float lebar) { //105
  z = height2 + h;
  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
  angle2 = round(angle1 - legoffset[3]) + 15; //15

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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //71

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 142; //140
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BL3 (float x, float y, float h, float lebar) { //19
  z = height2 + h;
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  angle2 = round(angle1 - legoffset[2]) + 10; //10

  if (angle2 < 195) sdtcoxa = angle2 + lebar;
  if (angle2 > 195) sdtcoxa = angle2 - lebar;
  if (angle2 == 195) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));

  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 153; //149
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void rotRightTangga(float sdt) { //Default 10 derajat
  movecounter++;
  if (movecounter == 1) {
    FRRot(55, 55, 20, sdt);
    BLRot(-55, -55, 20, sdt);
    FLRot(-55, 55, 0, sdt);
    BRRot(55, -55, 0, sdt);
    delay(tr2);

    FRRot(52.59, 57.41, 17.78, sdt);
    BLRot(-52.59, -57.41, 17.78, sdt);
    FLRot(-54.7, 55.3, 0, sdt);
    BRRot(54.7, -55.3, 0, sdt);
    delay(tr2);

    FRRot(50.74, 59.26, 11.11, sdt);
    BLRot(-50.74, -59.26, 11.11, sdt);
    FLRot(-54.4, 55.6, 0, sdt);
    BRRot(54.4, -55.6, 0, sdt);
    delay(tr2);

    ///////////////////////////////////////////////////
    FRRot(50.4, 59.6, 6.85, sdt);
    BLRot(-50.4, -59.6, 6.85, sdt);
    FLRot(-54.3, 55.7, 0, sdt);
    BRRot(54.3, -55.7, 0, sdt);
    delay(tr2);

    FRRot(50.28, 59.72, 2.3, sdt);
    BLRot(-50.28, -59.72, 2.3, sdt);
    FLRot(-54.2, 55.8, 0, sdt);
    BRRot(54.2, -55.8, 0, sdt);
    delay(tr2);
    //////////////////////////////////////////////////

    FRRot(50, 60, 0, sdt);
    BLRot(-50, -60, 0, sdt);
    FLRot(-54.1, 55.9, 0, sdt);
    BRRot(54.1, -55.9, 0, sdt);
    delay(tr2);
    ///////////////////////////////////////////////////
    FRRot(50.11, 59.89, 0, sdt);
    BLRot(-50.11, -59.89, 0, sdt);
    FLRot(-53.99, 56.01, 0, sdt);
    BRRot(53.99, -56.01, 0, sdt);
    delay(tr2);

    FRRot(50.43, 59.57, 0, sdt);
    BLRot(-50.43, -59.57, 0, sdt);
    FLRot(-53.67, 56.33, 0, sdt);
    BRRot(53.67, -56.33, 0, sdt);
    delay(tr2);

    FRRot(50.89, 59.11, 0, sdt);
    BLRot(-50.89, -59.11, 0, sdt);
    FLRot(-53.21, 56.79, 0, sdt);
    BRRot(53.21, -56.79, 0, sdt);
    delay(tr2);

    FRRot(51.44, 58.56, 0, sdt);
    BLRot(-51.44, -58.56, 0, sdt);
    FLRot(-52.66, 57.34, 0, sdt);
    BRRot(52.66, -57.34, 0, sdt);
    delay(tr2);

    FRRot(52.05, 57.95, 0, sdt);
    BLRot(-52.05, -57.95, 0, sdt);
    FLRot(-52.05, 57.95, 0, sdt);
    BRRot(52.05, -57.95, 0, sdt);
    delay(tr2);

    FRRot(52.66, 57.34, 0, sdt);
    BLRot(-52.66, -57.34, 0, sdt);
    FLRot(-51.44, 58.56, 0, sdt);
    BRRot(51.44, -58.56, 0, sdt);
    delay(tr2);

    FRRot(53.21, 56.79, 0, sdt);
    BLRot(-53.21, -56.79, 0, sdt);
    FLRot(-50.89, 59.11, 0, sdt);
    BRRot(50.89, -59.11, 0, sdt);
    delay(tr2);

    FRRot(53.67, 56.33, 0, sdt);
    BLRot(-53.67, -56.33, 0, sdt);
    FLRot(-50.43, 59.57, 0, sdt);
    BRRot(50.43, -59.57, 0, sdt);
    delay(tr2);

    FRRot(53.99, 56.01, 0, sdt);
    BLRot(-53.99, -56.01, 0, sdt);
    FLRot(-50.11, 59.89, 0, sdt);
    BRRot(50.11, -59.89, 0, sdt);
    delay(tr2);

    ///////////////////////////////////////////////////////
    FRRot(54.1, 55.9, 0, sdt);
    BLRot(-54.1, -55.9, 0, sdt);
    FLRot(-50, 60, 0, sdt);
    BRRot(50, -60, 0, sdt);
    delay(tr2);

    FRRot(54.40, 55.60, 0, sdt);
    BLRot(-54.40, -55.60, 0, sdt);
    FLRot(-50.74, 59.26, 11.11, sdt);
    BRRot(50.74, -59.26, 11.11, sdt);
    delay(tr2);

    FRRot(54.7, 55.3, 0, sdt);
    BLRot(-54.7, -55.3, 0, sdt);
    FLRot(-52.59, 57.41, 17.78, sdt);
    BRRot(52.59, -57.41, 17.78, sdt);
    delay(tr2);
  }
  else if (movecounter == 2) {
    FRRot(55, 55, 0, sdt);
    BLRot(-55, -55, 0, sdt);
    FLRot(-55, 55, 20, sdt);
    BRRot(55, -55, 20, sdt);
    delay(tr2);

    FRRot(55.3, 54.7, 0, sdt);
    BLRot(-55.3, -54.7, 0, sdt);
    FLRot(-57.41, 52.59, 17.78, sdt);
    BRRot(57.41, -52.59, 17.78, sdt);
    delay(tr2);

    FRRot(55.6, 54.4, 0, sdt);
    BLRot(-55.6, -54.4, 0, sdt);
    FLRot(-59.26, 50.74, 11.11, sdt);
    BRRot(59.26, -50.74, 11.11, sdt);
    delay(tr2);
    //////////////////////////////////////////

    FRRot(55.7, 54.3, 0, sdt);
    BLRot(-55.7, -54.3, 0, sdt);
    FLRot(-59.6, 50.4, 6.85, sdt);
    BRRot(59.6, -50.4, 6.85, sdt);
    delay(tr2);

    FRRot(55.8, 54.2, 0, sdt);
    BLRot(-55.8, -54.2, 0, sdt);
    FLRot(-59.72, 50.28, 2.3, sdt);
    BRRot(59.72, -50.28, 2.3, sdt);
    delay(tr2);
    ///////////////////////////////////////////
    FRRot(55.9, 54.1, 0, sdt);
    BLRot(-55.9, -54.1, 0, sdt);
    FLRot(-60, 50, 0, sdt);
    BRRot(60, -50, 0, sdt);
    delay(tr2);

    ////////////////////////////////////
    FRRot(56.01, 53.99, 0, sdt);
    BLRot(-56.01, -53.99, 0, sdt);
    FLRot(-59.89, 50.11, 0, sdt);
    BRRot(59.89, -50.11, 0, sdt);
    delay(tr2);

    FRRot(56.33, 53.67, 0, sdt);
    BLRot(-56.33, -53.67, 0, sdt);
    FLRot(-59.57, 50.43, 0, sdt);
    BRRot(59.57, -50.43, 0, sdt);
    delay(tr2);

    FRRot(56.79, 53.21, 0, sdt);
    BLRot(-56.79, -53.21, 0, sdt);
    FLRot(-59.11, 50.89, 0, sdt);
    BRRot(59.11, -50.89, 0, sdt);
    delay(tr2);

    FRRot(57.34, 52.66, 0, sdt);
    BLRot(-57.34, -52.66, 0, sdt);
    FLRot(-58.56, 51.44, 0, sdt);
    BRRot(58.56, -51.44, 0, sdt);
    delay(tr2);

    FRRot(57.95, 52.05, 0, sdt);
    BLRot(-57.95, -52.05, 0, sdt);
    FLRot(-57.95, 52.05, 0, sdt);
    BRRot(57.95, -52.05, 0, sdt);
    delay(tr2);

    FRRot(58.56, 51.44, 0, sdt);
    BLRot(-58.56, -51.44, 0, sdt);
    FLRot(-57.34, 52.66, 0, sdt);
    BRRot(57.34, -52.66, 0, sdt);
    delay(tr2);

    FRRot(59.11, 50.89, 0, sdt);
    BLRot(-59.11, -50.89, 0, sdt);
    FLRot(-56.79, 53.21, 0, sdt);
    BRRot(56.79, -53.21, 0, sdt);
    delay(tr2);

    FRRot(59.57, 50.43, 0, sdt);
    BLRot(-59.57, -50.43, 0, sdt);
    FLRot(-56.33, 53.67, 0, sdt);
    BRRot(56.33, -53.67, 0, sdt);
    delay(tr2);

    FRRot(59.89, 50.11, 0, sdt);
    BLRot(-59.89, -50.11, 0, sdt);
    FLRot(-56.01, 53.99, 0, sdt);
    BRRot(56.01, -53.99, 0, sdt);
    delay(tr2);

    ///////////////////////////////////////////
    FRRot(60, 50, 0, sdt);
    BLRot(-60, -50, 0, sdt);
    FLRot(-55.9, 54.1, 0, sdt);
    BRRot(55.9, -54.1, 0, sdt);
    delay(tr2);

    FRRot(59.26, 50.74, 11.11, sdt);
    BLRot(-59.26, -50.74, 11.11, sdt);
    FLRot(-55.6, 54.4, 0, sdt);
    BRRot(55.6, -54.4, 0, sdt);
    delay(tr2);

    FRRot(57.41, 52.59, 17.78, sdt);
    BLRot(-57.41, -52.59, 17.78, sdt);
    FLRot(-55.3, 54.7, 0, sdt);
    BRRot(55.3, -54.7, 0, sdt);
    delay(tr2);
    movecounter = 0;
  }
}

void rotLeftTangga(float sdt) { //Default 10 derajat
  movecounter++;
  if (movecounter == 1) {
    BRRot(55, -55, 0, sdt);
    FLRot(-55, 55, 0, sdt);
    FRRot(55, 55, 20, sdt);
    BLRot(-55, -55, 20, sdt);
    delay(tr2);
    /////////////////////Movecounter 1////////////////
    BRRot(55.3, -54.7, 0, sdt);
    FLRot(-55.3, 54.7, 0, sdt);
    FRRot(57.41, 52.59, 17.78, sdt);
    BLRot(-57.41, -52.59, 17.78, sdt);
    delay(tr2);

    BRRot(55.6, -54.4, 0, sdt);
    FLRot(-55.6, 54.4, 0, sdt);
    FRRot(59.26, 50.74, 11.11, sdt);
    BLRot(-59.26, -50.74, 11.11, sdt);
    delay(tr2);

    BRRot(55.7, -54.3, 0, sdt);
    FLRot(-55.7, 54.3, 0, sdt);
    FRRot(59.6, 50.4, 6.85, sdt);
    BLRot(-59.6, -50.4, 6.85, sdt);
    delay(tr2);

    BRRot(55.8, -54.2, 0, sdt);
    FLRot(-55.8, 54.2, 0, sdt);
    FRRot(59.72, 50.28, 2.3, sdt);
    BLRot(-59.72, -50.28, 2.3, sdt);
    delay(tr2);

    BRRot(55.9, -54.1, 0, sdt);
    FLRot(-55.9, 54.1, 0, sdt);
    FRRot(60, 50, 0, sdt);
    BLRot(-60, -50, 0, sdt);
    delay(tr2);

    BRRot(56.01, -53.99, 0, sdt);
    FLRot(-56.01, 53.99, 0, sdt);
    FRRot(59.89, 50.11, 0, sdt);
    BLRot(-59.89, -50.11, 0, sdt);
    delay(tr2);

    BRRot(56.33, -53.67, 0, sdt);
    FLRot(-56.33, 53.67, 0, sdt);
    FRRot(59.57, 50.43, 0, sdt);
    BLRot(-59.57, -50.43, 0, sdt);
    delay(tr2);

    BRRot(56.79, -53.21, 0, sdt);
    FLRot(-56.79, 53.21, 0, sdt);
    FRRot(59.11, 50.89, 0, sdt);
    BLRot(-59.11, -50.89, 0, sdt);
    delay(tr2);

    BRRot(57.34, -52.66, 0, sdt);
    FLRot(-57.34, 52.66, 0, sdt);
    FRRot(58.56, 51.44, 0, sdt);
    BLRot(-58.56, -51.44, 0, sdt);
    delay(tr2);

    BRRot(57.95, -52.05, 0, sdt);
    FLRot(-57.95, 52.05, 0, sdt);
    FRRot(57.95, 52.05, 0, sdt);
    BLRot(-57.95, -52.05, 0, sdt);
    delay(tr2);

    BRRot(58.56, -51.44, 0, sdt);
    FLRot(-58.56, 51.44, 0, sdt);
    FRRot(57.34, 52.66, 0, sdt);
    BLRot(-57.34, -52.66, 0, sdt);
    delay(tr2);

    BRRot(59.11, -50.89, 0, sdt);
    FLRot(-59.11, 50.89, 0, sdt);
    FRRot(56.79, 53.21, 0, sdt);
    BLRot(-56.79, -53.21, 0, sdt);
    delay(tr2);

    BRRot(59.57, -50.43, 0, sdt);
    FLRot(-59.57, 50.43, 0, sdt);
    FRRot(56.33, 53.67, 0, sdt);
    BLRot(-56.33, -53.67, 0, sdt);
    delay(tr2);

    BRRot(59.89, -50.11, 0, sdt);
    FLRot(-59.89, 50.11, 0, sdt);
    FRRot(56.01, 53.99, 0, sdt);
    BLRot(-56.01, -53.99, 0, sdt);
    delay(tr2);

    BRRot(60, -50, 0, sdt);
    FLRot(-60, 50, 0, sdt);
    FRRot(55.9, 54.1, 0, sdt);
    BLRot(-55.9, -54.1, 0, sdt);
    delay(tr2);

    BRRot(59.26, -50.74, 11.11, sdt);
    FLRot(-59.26, 50.74, 11.11, sdt);
    FRRot(55.6, 54.4, 0, sdt);
    BLRot(-55.6, -54.4, 0, sdt);
    delay(tr2);

    BRRot(57.41, -52.59, 17.78, sdt);
    FLRot(-57.41, 52.59, 17.78, sdt);
    FRRot(55.3, 54.7, 0, sdt);
    BLRot(-55.3, -54.7, 0, sdt);
    delay(tr2);
    //////////////////////////////////////////////
  }
  else if (movecounter == 2) {
    BRRot(55, -55, 20, sdt);
    FLRot(-55, 55, 20, sdt);
    FRRot(55, 55, 0, sdt);
    BLRot(-55, -55, 0, sdt);
    delay(tr2);
    //////////////////Movecounter 2////////////////////
    BRRot(52.59, -57.41, 17.78, sdt);
    FLRot(-52.59, 57.41, 17.78, sdt);
    FRRot(54.7, 55.3, 0, sdt);
    BLRot(-54.7, -55.3, 0, sdt);
    delay(tr2);

    BRRot(50.74, -59.26, 11.11, sdt);
    FLRot(-50.74, 59.26, 11.11, sdt);
    FRRot(54.4, 55.6, 0, sdt);
    BLRot(-54.4, -55.6, 0, sdt);
    delay(tr2);

    BRRot(50.4, -59.6, 6.85, sdt);
    FLRot(-50.4, 59.6, 6.85, sdt);
    FRRot(54.3, 55.7, 0, sdt);
    BLRot(-54.3, -55.7, 0, sdt);
    delay(tr2);

    BRRot(50.28, -59.72, 2.3, sdt);
    FLRot(-50.28, 59.72, 2.3, sdt);
    FRRot(54.2, 55.8, 0, sdt);
    BLRot(-54.2, -55.8, 0, sdt);
    delay(tr2);

    BRRot(50, -60, 0, sdt);
    FLRot(-50, 60, 0, sdt);
    FRRot(54.1, 55.9, 0, sdt);
    BLRot(-54.1, -55.9, 0, sdt);
    delay(tr2);

    BRRot(50.11, -59.89, 0, sdt);
    FLRot(-50.11, 59.89, 0, sdt);
    FRRot(53.99, 56.01, 0, sdt);
    BLRot(-53.99, -56.01, 0, sdt);
    delay(tr2);

    BRRot(50.43, -59.57, 0, sdt);
    FLRot(-50.43, 59.57, 0, sdt);
    FRRot(53.67, 56.33, 0, sdt);
    BLRot(-53.67, -56.33, 0, sdt);
    delay(tr2);

    BRRot(50.89, -59.11, 0, sdt);
    FLRot(-50.89, 59.11, 0, sdt);
    FRRot(53.21, 56.79, 0, sdt);
    BLRot(-53.21, -56.79, 0, sdt);
    delay(tr2);

    BRRot(51.44, -58.56, 0, sdt);
    FLRot(-51.44, 58.56, 0, sdt);
    FRRot(52.66, 57.34, 0, sdt);
    BLRot(-52.66, -57.34, 0, sdt);
    delay(tr2);

    BRRot(52.05, -57.95, 0, sdt);
    FLRot(-52.05, 57.95, 0, sdt);
    FRRot(52.05, 57.95, 0, sdt);
    BLRot(-52.05, -57.95, 0, sdt);
    delay(tr2);

    BRRot(52.66, -57.34, 0, sdt);
    FLRot(-52.66, 57.34, 0, sdt);
    FRRot(51.44, 58.56, 0, sdt);
    BLRot(-51.44, -58.56, 0, sdt);
    delay(tr2);

    BRRot(53.21, -56.79, 0, sdt);
    FLRot(-53.21, 56.79, 0, sdt);
    FRRot(50.89, 59.11, 0, sdt);
    BLRot(-50.89, -59.11, 0, sdt);
    delay(tr2);

    BRRot(53.67, -56.33, 0, sdt);
    FLRot(-53.67, 56.33, 0, sdt);
    FRRot(50.43, 59.57, 0, sdt);
    BLRot(-50.43, -59.57, 0, sdt);
    delay(tr2);

    BRRot(53.99, -56.01, 0, sdt);
    FLRot(-53.99, 56.01, 0, sdt);
    FRRot(50.11, 59.89, 0, sdt);
    BLRot(-50.11, -59.89, 0, sdt);
    delay(tr2);

    BRRot(54.1, -55.9, 0, sdt);
    FLRot(-54.1, 55.9, 0, sdt);
    FRRot(50, 60, 0, sdt);
    BLRot(-50, -60, 0, sdt);
    delay(tr2);

    BRRot(54.40, -55.60, 0, sdt);
    FLRot(-54.40, 55.60, 0, sdt);
    FRRot(50.74, 59.26, 11.11, sdt);
    BLRot(-50.74, -59.26, 11.11, sdt);
    delay(tr2);

    BRRot(54.7, -55.3, 0, sdt);
    FLRot(-54.7, 55.3, 0, sdt);
    FRRot(52.59, 57.41, 17.78, sdt);
    BLRot(-52.59, -57.41, 17.78, sdt);
    delay(tr2);
    movecounter = 0;
  }
}
