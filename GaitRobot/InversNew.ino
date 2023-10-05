void FRAuto(float x, float y, float z) {
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  sdtcoxa = round(angle1 - legoffset[0]) + 12; //11
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

void FLAuto(float x, float y, float z) { //105
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  sdtcoxa = round(angle1 - legoffset[1]) + 13; //18
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

void BLAuto(float x, float y, float z) { //195
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  sdtcoxa = round(angle1 - legoffset[2]) + 10; //10

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

void BRAuto(float x, float y, float z) { //105
  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
  sdtcoxa = round(angle1 - legoffset[3]) + 15; //15

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
//
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
// sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 158; //149
// kiri_bawah(sdtcoxa,sdtfemur,sdttibia);
//// Serial.println("BACK LEFT :"); 
//// Serial.print("CX :");
//// Serial.println(sdtcoxa);
//// Serial.print("FM :");
//// Serial.println(sdtfemur);
//// Serial.print("TB :");
//// Serial.println(sdttibia);
//}
