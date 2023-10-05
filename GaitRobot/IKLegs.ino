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

//================IK Transisi Tangga 2======================//
void FR6(float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 26; //6 //11  //24

  if (angle2 > 195) sdtcoxa = angle2 + lebar;
  if (angle2 == 195) sdtcoxa = angle2;
  if (angle2 < 195) sdtcoxa = angle2 - lebar;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 77; //97

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 150.5; //150
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  Serial2.println("FRONT RIGHT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
}

void FL6(float x, float y, float h, float lebar) { //105
  z = height + h;
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  angle2 = round(angle1 - legoffset[1]) - 4; //18 //3

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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 81; //101

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 153.5; //153
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  Serial2.println("FRONT LEFT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 39; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 91; //149 //89
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  Serial2.println("BACK LEFT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 39; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 78; //138 //80
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  Serial2.println("BACK RIGHT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
}
//================IK Transisi Tangga 2======================//

//================IK Transisi Tangga 1======================//
void FR4(float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 26; //11

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
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 150.5; //136
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  Serial2.println("FRONT RIGHT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
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
  Serial2.println("FRONT LEFT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
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
  Serial2.println("BACK LEFT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
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
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 129; //138
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  Serial2.println("BACK RIGHT :");
  Serial2.print("CX :");
  Serial2.println(sdtcoxa);
  Serial2.print("FM :");
  Serial2.println(sdtfemur);
  Serial2.print("TB :");
  Serial2.println(sdttibia);
}
//=================IK Transisi 1===============//

//================IK Naik Tangga======================//
void FR5(float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 34; //6 //11  //24

  if (angle2 > 195) sdtcoxa = angle2 + lebar;
  if (angle2 == 195) sdtcoxa = angle2;
  if (angle2 < 195) sdtcoxa = angle2 - lebar;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 97; //97

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 151; //150
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  Serial.println("FRONT RIGHT :");
  Serial.print("CX :");
  Serial.println(sdtcoxa);
  Serial.print("FM :");
  Serial.println(sdtfemur);
  Serial.print("TB :");
  Serial.println(sdttibia);
}

void FL5(float x, float y, float h, float lebar) { //105
  z = height + h;
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  angle2 = round(angle1 - legoffset[1]) - 4; //18 //3

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
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 153.5; //153
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  Serial.println("FRONT LEFT :");
  Serial.print("CX :");
  Serial.println(sdtcoxa);
  Serial.print("FM :");
  Serial.println(sdtfemur);
  Serial.print("TB :");
  Serial.println(sdttibia);
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
  Serial.println("BACK LEFT :");
  Serial.print("CX :");
  Serial.println(sdtcoxa);
  Serial.print("FM :");
  Serial.println(sdtfemur);
  Serial.print("TB :");
  Serial.println(sdttibia);
}

void BR5(float x, float y, float h, float lebar) { //105
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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 19; //19

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 81; //138 //80
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  Serial.println("BACK RIGHT :");
  Serial.print("CX :");
  Serial.println(sdtcoxa);
  Serial.print("FM :");
  Serial.println(sdtfemur);
  Serial.print("TB :");
  Serial.println(sdttibia);
}
//====================IK Naik Tangga====================//

//void FR(float x, float y, float h, float lebar) {
//  z = height + h;
//  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
//  angle2 = round(angle1 - legoffset[0]) + 11; //6
//
//  if (angle2 > 195) sdtcoxa = angle2 + lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//  if (angle2 < 195) sdtcoxa = angle2 - lebar;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //71
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 142; //139
//  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void FL (float x, float y, float h, float lebar) { //105
//  z = height + h;
//  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
//  angle2 = round(angle1 - legoffset[1]) + 13; //18
//
//  if (arahgerak == true) { //Maju & Mundur
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //Geser Kanan & Kiri
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 73; //74
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 150; //146
//  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BL (float x, float y, float h, float lebar) { //195
//  z = height2 + h;
//  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
//  angle2 = round(angle1 - legoffset[2]) + 10; //10
//
//  if (angle2 < 195) sdtcoxa = angle2 + lebar;
//  if (angle2 > 195) sdtcoxa = angle2 - lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 150; //149
//  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BR (float x, float y, float h, float lebar) { //105
//  z = height2 + h;
//  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
//  angle2 = round(angle1 - legoffset[3]) + 15; //15
//
//  if (arahgerak == true) { //maju mundur
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //geser kanan kiri
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
//  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
//  // if (angle2 == 105) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 71; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 137; //138
//  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}

////==========Invers Gerak Korban 3=========//
//void FR(float x, float y, float h, float lebar) {
//  z = height + h;
//  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
//  angle2 = round(angle1 - legoffset[0]) + 11; //6
//
//  if (angle2 > 195) sdtcoxa = angle2 + lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//  if (angle2 < 195) sdtcoxa = angle2 - lebar;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //71
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 139; //139
//  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void FL (float x, float y, float h, float lebar) { //105
//  z = height + h;
//  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
//  angle2 = round(angle1 - legoffset[1]) + 13; //18
//
//  if (arahgerak == true) { //Maju & Mundur
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //Geser Kanan & Kiri
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //74
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 146; //146
//  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BL (float x, float y, float h, float lebar) { //195
//  z = height2 + h;
//  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
//  angle2 = round(angle1 - legoffset[2]) + 10; //10
//
//  if (angle2 < 195) sdtcoxa = angle2 + lebar;
//  if (angle2 > 195) sdtcoxa = angle2 - lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 146; //149
//  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BR (float x, float y, float h, float lebar) { //105
//  z = height2 + h;
//  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
//  angle2 = round(angle1 - legoffset[3]) + 15; //15
//
//  if (arahgerak == true) { //maju mundur
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //geser kanan kiri
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
//  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
//  // if (angle2 == 105) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 138; //138
//  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//================Invers Gerak Korban 3============//

//void FR(float x, float y, float h, float lebar) {
//  z = height + h;
//  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
//  angle2 = round(angle1 - legoffset[0]) + 11; //6
//
//  if (angle2 > 195) sdtcoxa = angle2 + lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//  if (angle2 < 195) sdtcoxa = angle2 - lebar;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //71
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 134; //139
//  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void FL (float x, float y, float h, float lebar) { //105
//  z = height + h;
//  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
//  angle2 = round(angle1 - legoffset[1]) + 13; //18
//
//  if (arahgerak == true) { //Maju & Mundur
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //Geser Kanan & Kiri
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 75; //74
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 146; //146
//  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BL (float x, float y, float h, float lebar) { //195
//  z = height2 + h;
//  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
//  angle2 = round(angle1 - legoffset[2]) + 10; //10
//
//  if (angle2 < 195) sdtcoxa = angle2 + lebar;
//  if (angle2 > 195) sdtcoxa = angle2 - lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 143; //149
//  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BR (float x, float y, float h, float lebar) { //105
//  z = height2 + h;
//  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
//  angle2 = round(angle1 - legoffset[3]) + 15; //15
//
//  if (arahgerak == true) { //maju mundur
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //geser kanan kiri
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
//  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
//  // if (angle2 == 105) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 71; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 138; //138
//  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}


//===========IK Ambil Korban 3=========//
//void FR(float x, float y, float h, float lebar) {
//  z = height + h;
//  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
//  angle2 = round(angle1 - legoffset[0]) + 11; //6
//
//  if (angle2 > 195) sdtcoxa = angle2 + lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//  if (angle2 < 195) sdtcoxa = angle2 - lebar;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //71
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 139; //139
//  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void FL (float x, float y, float h, float lebar) { //105
//  z = height + h;
//  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
//  angle2 = round(angle1 - legoffset[1]) + 13; //18
//
//  if (arahgerak == true) { //Maju & Mundur
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //Geser Kanan & Kiri
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 73; //74
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 146; //146
//  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BL (float x, float y, float h, float lebar) { //195
//  z = height2 + h;
//  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
//  angle2 = round(angle1 - legoffset[2]) + 10; //10
//
//  if (angle2 < 195) sdtcoxa = angle2 + lebar;
//  if (angle2 > 195) sdtcoxa = angle2 - lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 143; //149
//  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BR (float x, float y, float h, float lebar) { //105
//  z = height2 + h;
//  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
//  angle2 = round(angle1 - legoffset[3]) + 15; //15
//
//  if (arahgerak == true) { //maju mundur
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //geser kanan kiri
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
//  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
//  // if (angle2 == 105) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 71; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 136; //138
//  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//==========IK Ambil Korban 3============//

////IK Transisi Tangga
//void FR(float x, float y, float h, float lebar) {
//  z = height + h;
//  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
//  angle2 = round(angle1 - legoffset[0]) + 26; //11
//
//  if (angle2 > 195) sdtcoxa = angle2 + lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//  if (angle2 < 195) sdtcoxa = angle2 - lebar;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 150.5; //136
//  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void FL (float x, float y, float h, float lebar) { //105
//  z = height + h;
//  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
//  angle2 = round(angle1 - legoffset[1]) - 4; //13
//
//  if (arahgerak == true) { //Maju & Mundur
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //Geser Kanan & Kiri
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 76; //71
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 153.5; //146
//  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BL (float x, float y, float h, float lebar) { //195
//  z = height2 + h;
//  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
//  angle2 = round(angle1 - legoffset[2]) + 3; //10
//
//  if (angle2 < 195) sdtcoxa = angle2 + lebar;
//  if (angle2 > 195) sdtcoxa = angle2 - lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 68; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 136; //141
//  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BR (float x, float y, float h, float lebar) { //105
//  z = height2 + h;
//  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
//  angle2 = round(angle1 - legoffset[3]) + 22; //15
//
//  if (arahgerak == true) { //maju mundur
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //geser kanan kiri
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
//  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
//  // if (angle2 == 105) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 67; //71
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 129; //138
//  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
////================IK Transisi 2======================//
//void FR1(float x, float y, float h, float lebar) {
//  z = height + h;
//  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
//  angle2 = round(angle1 - legoffset[0]) + 26; //6 //11  //24
//
//  if (angle2 > 195) sdtcoxa = angle2 + lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//  if (angle2 < 195) sdtcoxa = angle2 - lebar;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 77; //97
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 150.5; //150
//  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void FL1(float x, float y, float h, float lebar) { //105
//  z = height + h;
//  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
//  angle2 = round(angle1 - legoffset[1]) - 4; //18 //3
//
//  if (arahgerak == true) { //Maju & Mundur
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //Geser Kanan & Kiri
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 81; //101
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 153.5; //153
//  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("FRONT LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//
//void BL1 (float x, float y, float h, float lebar) { //195
//  z = height2 + h;
//  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
//  angle2 = round(angle1 - legoffset[2]) - 7; //5
//
//  if (angle2 < 195) sdtcoxa = angle2 + lebar;
//  if (angle2 > 195) sdtcoxa = angle2 - lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 39; //19
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 91; //149 //89
//  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//void BR1 (float x, float y, float h, float lebar) { //105
//  z = height2 + h;
//  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
//  angle2 = round(angle1 - legoffset[3]) + 32; //20
//
//  if (arahgerak == true) { //maju mundur
//    if (angle2 < 105) sdtcoxa = angle2 - lebar;
//    if (angle2 > 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//  if (arahgerak == false) { //geser kanan kiri
//    if (angle2 > 105) sdtcoxa = angle2 - lebar;
//    if (angle2 < 105) sdtcoxa = angle2 + lebar;
//    if (angle2 == 105) sdtcoxa = angle2;
//  }
//
//  // if (angle2 < 105) sdtcoxa = angle2 - lebar;
//  // if (angle2 > 105) sdtcoxa = angle2 + lebar;
//  // if (angle2 == 105) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 39; //19
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 78; //138 //80
//  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK RIGHT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}
//====================IK Naik Tangga====================//


//void BL2 (float x, float y, float h, float lebar) { //19
//  z = height2 + h;
//  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
//  angle2 = round(angle1 - legoffset[2]) + 10; //10
//
//  if (angle2 < 195) sdtcoxa = angle2 + lebar;
//  if (angle2 > 195) sdtcoxa = angle2 - lebar;
//  if (angle2 == 195) sdtcoxa = angle2;
//
//  P = sqrt((x * x) + (y * y));
//  alas = P - cx;
//  c = sqrt((alas * alas) + (z * z));
//
//  alpha = atan(z / alas);
//  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
//  theta2 = alpha + beta;
//  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
//  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
//  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 149; //149
//  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
//  // Serial.println("BACK LEFT :");
//  // Serial.print("CX :");
//  // Serial.println(sdtcoxa);
//  // Serial.print("FM :");
//  // Serial.println(sdtfemur);
//  // Serial.print("TB :");
//  // Serial.println(sdttibia);
//}

//void BL3 (float x, float y, float h, float lebar){//19
//  z = height2 + h;
// if (x<0&&y<0) angle1 = round (180 + (atan(y/x)*57.296) + 180); //Kiri Bawah
// angle2 = round(angle1 - legoffset[2]) + 10; //10
//
// if (angle2 < 195) sdtcoxa = angle2 + lebar;
// if (angle2 > 195) sdtcoxa = angle2 - lebar;
// if (angle2 == 195) sdtcoxa = angle2;
//
// P = sqrt((x*x) + (y*y));
// alas = P - cx;
// c = sqrt((alas*alas) + (z*z));
//
// alpha = atan(z/alas);
// beta = acos((fm*fm + c*c - tb*tb)/(2*fm*c));
// theta2 = alpha + beta;
// sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //72
//
// theta3 = acos((tb*tb + fm*fm - c*c)/(2*tb*fm));
// sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 159; //149
// kiri_bawah(sdtcoxa,sdtfemur,sdttibia);
//// Serial.println("BACK LEFT :");
//// Serial.print("CX :");
//// Serial.println(sdtcoxa);
//// Serial.print("FM :");
//// Serial.println(sdtfemur);
//// Serial.print("TB :");
//// Serial.println(sdttibia);
//}

//Coba cari"
void kiri_bawah(float k, float l, float m) {
  //dxl.setGoalVelocity(1, s, UNIT_RAW);
  dxl.setGoalPosition(1, k, UNIT_DEGREE);
  //dxl.setGoalVelocity(2, s, UNIT_RAW);
  dxl.setGoalPosition(2, l, UNIT_DEGREE);
  //dxl.setGoalVelocity(3, s, UNIT_RAW);
  dxl.setGoalPosition(3, m, UNIT_DEGREE);
  //DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID);
}
void kanan_atas(float a, float b, float c) {
  //dxl.setGoalVelocity(7, s, UNIT_RAW);
  dxl.setGoalPosition(7, a, UNIT_DEGREE);
  //dxl.setGoalVelocity(8, s, UNIT_RAW);
  dxl.setGoalPosition(8, b, UNIT_DEGREE);
  //dxl.setGoalVelocity(9, s, UNIT_RAW);
  dxl.setGoalPosition(9, c, UNIT_DEGREE);
}
void kanan_bawah(float d, float e, float f) {
  //dxl.setGoalVelocity(4, s, UNIT_RAW);
  dxl.setGoalPosition(4, d, UNIT_DEGREE);
  //dxl.setGoalVelocity(5, s, UNIT_RAW);
  dxl.setGoalPosition(5, e, UNIT_DEGREE);
  //dxl.setGoalVelocity(6, s, UNIT_RAW);
  dxl.setGoalPosition(6, f, UNIT_DEGREE);
}
void kiri_atas(float h, float i, float j) {
  //dxl.setGoalVelocity(10, s, UNIT_RAW);
  dxl.setGoalPosition(10, h, UNIT_DEGREE);
  //dxl.setGoalVelocity(11, s, UNIT_RAW);
  dxl.setGoalPosition(11, i, UNIT_DEGREE);
  //dxl.setGoalVelocity(12, s, UNIT_RAW);
  dxl.setGoalPosition(12, j, UNIT_DEGREE);
}

void IKRot(float x, float y, float h) {
  z = height + h;
  if (x >= 0 && y >= 0) {
    angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas(FR)
    sdtcoxa1 = round(angle1 - legoffset[0]) + 15;
  }
  else if (x < 0 && y >= 0) {
    angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas(FL)
    sdtcoxa2 = round(angle1 - legoffset[1]) + 15;
  }
  else if (x < 0 && y < 0) {
    angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah(BL)
    sdtcoxa3 = round(angle1 - legoffset[2]) + 15;
  }
  else if (x >= 0 && y < 0) {
    angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah(BR)
    sdtcoxa4 = round(angle1 - legoffset[3]) + 15;
  }

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 72 ;

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 144; //138

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 144;
}



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
