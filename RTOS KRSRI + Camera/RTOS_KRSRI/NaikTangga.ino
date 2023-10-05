//================IK Rotate Naik Tangga======================//
void FRRot1(float x, float y, float h, float sudut) {
  z = height + h;
  if (x >= 0 && y >= 0) {
    angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas(FR)
    angle2 = round(angle1 - legoffset[0]) + 31;  //asli 26
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

void FLRot1(float x, float y, float h, float sudut) { //105
  z = height + h;
  if (x < 0 && y >= 0) {
    angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas(FL)
    angle2 = round(angle1 - legoffset[1]) - 2;
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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 86; //101

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 155; //153
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BLRot1(float x, float y, float h, float sudut) { //195
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

void BRRot1(float x, float y, float h, float sudut) { //105
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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 31; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 84; //138 //80
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
void rotRightTransisi(float sdt) { //Default 10 derajat
  movecounter++;
  if (movecounter == 1) {
    FRRot1(55, 55, 30, sdt);
    BLRot1(-55, -55, 30, sdt);
    FLRot1(-55, 55, 0, sdt);
    BRRot1(55, -55, 0, sdt);
    delay(drot);

    FRRot1(52.59, 57.41, 26.67, sdt);
    BLRot1(-52.59, -57.41, 26.67, sdt);
    FLRot1(-54.7, 55.3, 0, sdt);
    BRRot1(54.7, -55.3, 0, sdt);
    delay(drot);

    FRRot1(50.74, 59.26, 16.67, sdt);
    BLRot1(-50.74, -59.26, 16.67, sdt);
    FLRot1(-54.4, 55.6, 0, sdt);
    BRRot1(54.4, -55.6, 0, sdt);
    delay(drot);

    ///////////////////////////////////////////////////
    FRRot1(50.4, 59.6, 10.85, sdt);
    BLRot1(-50.4, -59.6, 10.85, sdt);
    FLRot1(-54.3, 55.7, 0, sdt);
    BRRot1(54.3, -55.7, 0, sdt);
    delay(drot);

    FRRot1(50.28, 59.72, 4.3, sdt);
    BLRot1(-50.28, -59.72, 4.3, sdt);
    FLRot1(-54.2, 55.8, 0, sdt);
    BRRot1(54.2, -55.8, 0, sdt);
    delay(drot);
    //////////////////////////////////////////////////

    FRRot1(50, 60, 0, sdt);
    BLRot1(-50, -60, 0, sdt);
    FLRot1(-54.1, 55.9, 0, sdt);
    BRRot1(54.1, -55.9, 0, sdt);
    delay(drot);
    ///////////////////////////////////////////////////
    FRRot1(50.11, 59.89, 0, sdt);
    BLRot1(-50.11, -59.89, 0, sdt);
    FLRot1(-53.99, 56.01, 0, sdt);
    BRRot1(53.99, -56.01, 0, sdt);
    delay(drot);

    FRRot1(50.43, 59.57, 0, sdt);
    BLRot1(-50.43, -59.57, 0, sdt);
    FLRot1(-53.67, 56.33, 0, sdt);
    BRRot1(53.67, -56.33, 0, sdt);
    delay(drot);

    FRRot1(50.89, 59.11, 0, sdt);
    BLRot1(-50.89, -59.11, 0, sdt);
    FLRot1(-53.21, 56.79, 0, sdt);
    BRRot1(53.21, -56.79, 0, sdt);
    delay(drot);

    FRRot1(51.44, 58.56, 0, sdt);
    BLRot1(-51.44, -58.56, 0, sdt);
    FLRot1(-52.66, 57.34, 0, sdt);
    BRRot1(52.66, -57.34, 0, sdt);
    delay(drot);

    FRRot1(52.05, 57.95, 0, sdt);
    BLRot1(-52.05, -57.95, 0, sdt);
    FLRot1(-52.05, 57.95, 0, sdt);
    BRRot1(52.05, -57.95, 0, sdt);
    delay(drot);

    FRRot1(52.66, 57.34, 0, sdt);
    BLRot1(-52.66, -57.34, 0, sdt);
    FLRot1(-51.44, 58.56, 0, sdt);
    BRRot1(51.44, -58.56, 0, sdt);
    delay(drot);

    FRRot1(53.21, 56.79, 0, sdt);
    BLRot1(-53.21, -56.79, 0, sdt);
    FLRot1(-50.89, 59.11, 0, sdt);
    BRRot1(50.89, -59.11, 0, sdt);
    delay(drot);

    FRRot1(53.67, 56.33, 0, sdt);
    BLRot1(-53.67, -56.33, 0, sdt);
    FLRot1(-50.43, 59.57, 0, sdt);
    BRRot1(50.43, -59.57, 0, sdt);
    delay(drot);

    FRRot1(53.99, 56.01, 0, sdt);
    BLRot1(-53.99, -56.01, 0, sdt);
    FLRot1(-50.11, 59.89, 0, sdt);
    BRRot1(50.11, -59.89, 0, sdt);
    delay(drot);

    ///////////////////////////////////////////////////////
    FRRot1(54.1, 55.9, 0, sdt);
    BLRot1(-54.1, -55.9, 0, sdt);
    FLRot1(-50, 60, 0, sdt);
    BRRot1(50, -60, 0, sdt);
    delay(drot);

    FRRot1(54.40, 55.60, 0, sdt);
    BLRot1(-54.40, -55.60, 0, sdt);
    FLRot1(-50.74, 59.26, 16.67, sdt);
    BRRot1(50.74, -59.26, 16.67, sdt);
    delay(drot);

    FRRot1(54.7, 55.3, 0, sdt);
    BLRot1(-54.7, -55.3, 0, sdt);
    FLRot1(-52.59, 57.41, 26.67, sdt);
    BRRot1(52.59, -57.41, 26.67, sdt);
    delay(drot);
  }
  else if (movecounter == 2) {
    FRRot1(55, 55, 0, sdt);
    BLRot1(-55, -55, 0, sdt);
    FLRot1(-55, 55, 30, sdt);
    BRRot1(55, -55, 30, sdt);
    delay(drot);

    FRRot1(55.3, 54.7, 0, sdt);
    BLRot1(-55.3, -54.7, 0, sdt);
    FLRot1(-57.41, 52.59, 26.67, sdt);
    BRRot1(57.41, -52.59, 26.67, sdt);
    delay(drot);

    FRRot1(55.6, 54.4, 0, sdt);
    BLRot1(-55.6, -54.4, 0, sdt);
    FLRot1(-59.26, 50.74, 16.67, sdt);
    BRRot1(59.26, -50.74, 16.67, sdt);
    delay(drot);
    //////////////////////////////////////////

    FRRot1(55.7, 54.3, 0, sdt);
    BLRot1(-55.7, -54.3, 0, sdt);
    FLRot1(-59.6, 50.4, 10.85, sdt);
    BRRot1(59.6, -50.4, 10.85, sdt);
    delay(drot);

    FRRot1(55.8, 54.2, 0, sdt);
    BLRot1(-55.8, -54.2, 0, sdt);
    FLRot1(-59.72, 50.28, 4.3, sdt);
    BRRot1(59.72, -50.28, 4.3, sdt);
    delay(drot);
    ///////////////////////////////////////////
    FRRot1(55.9, 54.1, 0, sdt);
    BLRot1(-55.9, -54.1, 0, sdt);
    FLRot1(-60, 50, 0, sdt);
    BRRot1(60, -50, 0, sdt);
    delay(drot);

    ////////////////////////////////////
    FRRot1(56.01, 53.99, 0, sdt);
    BLRot1(-56.01, -53.99, 0, sdt);
    FLRot1(-59.89, 50.11, 0, sdt);
    BRRot1(59.89, -50.11, 0, sdt);
    delay(drot);

    FRRot1(56.33, 53.67, 0, sdt);
    BLRot1(-56.33, -53.67, 0, sdt);
    FLRot1(-59.57, 50.43, 0, sdt);
    BRRot1(59.57, -50.43, 0, sdt);
    delay(drot);

    FRRot1(56.79, 53.21, 0, sdt);
    BLRot1(-56.79, -53.21, 0, sdt);
    FLRot1(-59.11, 50.89, 0, sdt);
    BRRot1(59.11, -50.89, 0, sdt);
    delay(drot);

    FRRot1(57.34, 52.66, 0, sdt);
    BLRot1(-57.34, -52.66, 0, sdt);
    FLRot1(-58.56, 51.44, 0, sdt);
    BRRot1(58.56, -51.44, 0, sdt);
    delay(drot);

    FRRot1(57.95, 52.05, 0, sdt);
    BLRot1(-57.95, -52.05, 0, sdt);
    FLRot1(-57.95, 52.05, 0, sdt);
    BRRot1(57.95, -52.05, 0, sdt);
    delay(drot);

    FRRot1(58.56, 51.44, 0, sdt);
    BLRot1(-58.56, -51.44, 0, sdt);
    FLRot1(-57.34, 52.66, 0, sdt);
    BRRot1(57.34, -52.66, 0, sdt);
    delay(drot);

    FRRot1(59.11, 50.89, 0, sdt);
    BLRot1(-59.11, -50.89, 0, sdt);
    FLRot1(-56.79, 53.21, 0, sdt);
    BRRot1(56.79, -53.21, 0, sdt);
    delay(drot);

    FRRot1(59.57, 50.43, 0, sdt);
    BLRot1(-59.57, -50.43, 0, sdt);
    FLRot1(-56.33, 53.67, 0, sdt);
    BRRot1(56.33, -53.67, 0, sdt);
    delay(drot);

    FRRot1(59.89, 50.11, 0, sdt);
    BLRot1(-59.89, -50.11, 0, sdt);
    FLRot1(-56.01, 53.99, 0, sdt);
    BRRot1(56.01, -53.99, 0, sdt);
    delay(drot);

    ///////////////////////////////////////////
    FRRot1(60, 50, 0, sdt);
    BLRot1(-60, -50, 0, sdt);
    FLRot1(-55.9, 54.1, 0, sdt);
    BRRot1(55.9, -54.1, 0, sdt);
    delay(drot);

    FRRot1(59.26, 50.74, 16.67, sdt);
    BLRot1(-59.26, -50.74, 16.67, sdt);
    FLRot1(-55.6, 54.4, 0, sdt);
    BRRot1(55.6, -54.4, 0, sdt);
    delay(drot);

    FRRot1(57.41, 52.59, 26.67, sdt);
    BLRot1(-57.41, -52.59, 26.67, sdt);
    FLRot1(-55.3, 54.7, 0, sdt);
    BRRot1(55.3, -54.7, 0, sdt);
    delay(drot);
    movecounter = 0;
  }
}

void rotLeftTransisi(float sdt) { //Default 10 derajat
  movecounter++;
  if (movecounter == 1) {
    BRRot1(55, -55, 0, sdt);
    FLRot1(-55, 55, 0, sdt);
    FRRot1(55, 55, 30, sdt);
    BLRot1(-55, -55, 30, sdt);
    delay(drot);
    /////////////////////Movecounter 1////////////////
    BRRot1(55.3, -54.7, 0, sdt);
    FLRot1(-55.3, 54.7, 0, sdt);
    FRRot1(57.41, 52.59, 26.67, sdt);
    BLRot1(-57.41, -52.59, 26.67, sdt);
    delay(drot);

    BRRot1(55.6, -54.4, 0, sdt);
    FLRot1(-55.6, 54.4, 0, sdt);
    FRRot1(59.26, 50.74, 16.67, sdt);
    BLRot1(-59.26, -50.74, 16.67, sdt);
    delay(drot);

    BRRot1(55.7, -54.3, 0, sdt);
    FLRot1(-55.7, 54.3, 0, sdt);
    FRRot1(59.6, 50.4, 10.85, sdt);
    BLRot1(-59.6, -50.4, 10.85, sdt);
    delay(drot);

    BRRot1(55.8, -54.2, 0, sdt);
    FLRot1(-55.8, 54.2, 0, sdt);
    FRRot1(59.72, 50.28, 4.3, sdt);
    BLRot1(-59.72, -50.28, 4.3, sdt);
    delay(drot);

    BRRot1(55.9, -54.1, 0, sdt);
    FLRot1(-55.9, 54.1, 0, sdt);
    FRRot1(60, 50, 0, sdt);
    BLRot1(-60, -50, 0, sdt);
    delay(drot);

    BRRot1(56.01, -53.99, 0, sdt);
    FLRot1(-56.01, 53.99, 0, sdt);
    FRRot1(59.89, 50.11, 0, sdt);
    BLRot1(-59.89, -50.11, 0, sdt);
    delay(drot);

    BRRot1(56.33, -53.67, 0, sdt);
    FLRot1(-56.33, 53.67, 0, sdt);
    FRRot1(59.57, 50.43, 0, sdt);
    BLRot1(-59.57, -50.43, 0, sdt);
    delay(drot);

    BRRot1(56.79, -53.21, 0, sdt);
    FLRot1(-56.79, 53.21, 0, sdt);
    FRRot1(59.11, 50.89, 0, sdt);
    BLRot1(-59.11, -50.89, 0, sdt);
    delay(drot);

    BRRot1(57.34, -52.66, 0, sdt);
    FLRot1(-57.34, 52.66, 0, sdt);
    FRRot1(58.56, 51.44, 0, sdt);
    BLRot1(-58.56, -51.44, 0, sdt);
    delay(drot);

    BRRot1(57.95, -52.05, 0, sdt);
    FLRot1(-57.95, 52.05, 0, sdt);
    FRRot1(57.95, 52.05, 0, sdt);
    BLRot1(-57.95, -52.05, 0, sdt);
    delay(drot);

    BRRot1(58.56, -51.44, 0, sdt);
    FLRot1(-58.56, 51.44, 0, sdt);
    FRRot1(57.34, 52.66, 0, sdt);
    BLRot1(-57.34, -52.66, 0, sdt);
    delay(drot);

    BRRot1(59.11, -50.89, 0, sdt);
    FLRot1(-59.11, 50.89, 0, sdt);
    FRRot1(56.79, 53.21, 0, sdt);
    BLRot1(-56.79, -53.21, 0, sdt);
    delay(drot);

    BRRot1(59.57, -50.43, 0, sdt);
    FLRot1(-59.57, 50.43, 0, sdt);
    FRRot1(56.33, 53.67, 0, sdt);
    BLRot1(-56.33, -53.67, 0, sdt);
    delay(drot);

    BRRot1(59.89, -50.11, 0, sdt);
    FLRot1(-59.89, 50.11, 0, sdt);
    FRRot1(56.01, 53.99, 0, sdt);
    BLRot1(-56.01, -53.99, 0, sdt);
    delay(drot);

    BRRot1(60, -50, 0, sdt);
    FLRot1(-60, 50, 0, sdt);
    FRRot1(55.9, 54.1, 0, sdt);
    BLRot1(-55.9, -54.1, 0, sdt);
    delay(drot);

    BRRot1(59.26, -50.74, 16.67, sdt);
    FLRot1(-59.26, 50.74, 16.67, sdt);
    FRRot1(55.6, 54.4, 0, sdt);
    BLRot1(-55.6, -54.4, 0, sdt);
    delay(drot);

    BRRot1(57.41, -52.59, 26.67, sdt);
    FLRot1(-57.41, 52.59, 26.67, sdt);
    FRRot1(55.3, 54.7, 0, sdt);
    BLRot1(-55.3, -54.7, 0, sdt);
    delay(drot);
    //////////////////////////////////////////////
  }
  else if (movecounter == 2) {
    BRRot1(55, -55, 30, sdt);
    FLRot1(-55, 55, 30, sdt);
    FRRot1(55, 55, 0, sdt);
    BLRot1(-55, -55, 0, sdt);
    delay(drot);
    //////////////////Movecounter 2////////////////////
    BRRot1(52.59, -57.41, 26.67, sdt);
    FLRot1(-52.59, 57.41, 26.67, sdt);
    FRRot1(54.7, 55.3, 0, sdt);
    BLRot1(-54.7, -55.3, 0, sdt);
    delay(drot);

    BRRot1(50.74, -59.26, 16.67, sdt);
    FLRot1(-50.74, 59.26, 16.67, sdt);
    FRRot1(54.4, 55.6, 0, sdt);
    BLRot1(-54.4, -55.6, 0, sdt);
    delay(drot);

    BRRot1(50.4, -59.6, 10.85, sdt);
    FLRot1(-50.4, 59.6, 10.85, sdt);
    FRRot1(54.3, 55.7, 0, sdt);
    BLRot1(-54.3, -55.7, 0, sdt);
    delay(drot);

    BRRot1(50.28, -59.72, 4.3, sdt);
    FLRot1(-50.28, 59.72, 4.3, sdt);
    FRRot1(54.2, 55.8, 0, sdt);
    BLRot1(-54.2, -55.8, 0, sdt);
    delay(drot);

    BRRot1(50, -60, 0, sdt);
    FLRot1(-50, 60, 0, sdt);
    FRRot1(54.1, 55.9, 0, sdt);
    BLRot1(-54.1, -55.9, 0, sdt);
    delay(drot);

    BRRot1(50.11, -59.89, 0, sdt);
    FLRot1(-50.11, 59.89, 0, sdt);
    FRRot1(53.99, 56.01, 0, sdt);
    BLRot1(-53.99, -56.01, 0, sdt);
    delay(drot);

    BRRot1(50.43, -59.57, 0, sdt);
    FLRot1(-50.43, 59.57, 0, sdt);
    FRRot1(53.67, 56.33, 0, sdt);
    BLRot1(-53.67, -56.33, 0, sdt);
    delay(drot);

    BRRot1(50.89, -59.11, 0, sdt);
    FLRot1(-50.89, 59.11, 0, sdt);
    FRRot1(53.21, 56.79, 0, sdt);
    BLRot1(-53.21, -56.79, 0, sdt);
    delay(drot);

    BRRot1(51.44, -58.56, 0, sdt);
    FLRot1(-51.44, 58.56, 0, sdt);
    FRRot1(52.66, 57.34, 0, sdt);
    BLRot1(-52.66, -57.34, 0, sdt);
    delay(drot);

    BRRot1(52.05, -57.95, 0, sdt);
    FLRot1(-52.05, 57.95, 0, sdt);
    FRRot1(52.05, 57.95, 0, sdt);
    BLRot1(-52.05, -57.95, 0, sdt);
    delay(drot);

    BRRot1(52.66, -57.34, 0, sdt);
    FLRot1(-52.66, 57.34, 0, sdt);
    FRRot1(51.44, 58.56, 0, sdt);
    BLRot1(-51.44, -58.56, 0, sdt);
    delay(drot);

    BRRot1(53.21, -56.79, 0, sdt);
    FLRot1(-53.21, 56.79, 0, sdt);
    FRRot1(50.89, 59.11, 0, sdt);
    BLRot1(-50.89, -59.11, 0, sdt);
    delay(drot);

    BRRot1(53.67, -56.33, 0, sdt);
    FLRot1(-53.67, 56.33, 0, sdt);
    FRRot1(50.43, 59.57, 0, sdt);
    BLRot1(-50.43, -59.57, 0, sdt);
    delay(drot);

    BRRot1(53.99, -56.01, 0, sdt);
    FLRot1(-53.99, 56.01, 0, sdt);
    FRRot1(50.11, 59.89, 0, sdt);
    BLRot1(-50.11, -59.89, 0, sdt);
    delay(drot);

    BRRot1(54.1, -55.9, 0, sdt);
    FLRot1(-54.1, 55.9, 0, sdt);
    FRRot1(50, 60, 0, sdt);
    BLRot1(-50, -60, 0, sdt);
    delay(drot);

    BRRot1(54.40, -55.60, 0, sdt);
    FLRot1(-54.40, 55.60, 0, sdt);
    FRRot1(50.74, 59.26, 16.67, sdt);
    BLRot1(-50.74, -59.26, 16.67, sdt);
    delay(drot);

    BRRot1(54.7, -55.3, 0, sdt);
    FLRot1(-54.7, 55.3, 0, sdt);
    FRRot1(52.59, 57.41, 26.67, sdt);
    BLRot1(-52.59, -57.41, 26.67, sdt);
    delay(drot);
    movecounter = 0;
  }
}
