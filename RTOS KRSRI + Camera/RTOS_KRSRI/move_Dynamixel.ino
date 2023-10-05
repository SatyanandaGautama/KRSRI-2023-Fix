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

//IK untuk Ambil Korban 2
void FR2(float x, float y, float h, float lebar) {
  z = height + h;
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  angle2 = round(angle1 - legoffset[0]) + 10; //6

  if (angle2 > 195) sdtcoxa = angle2 + lebar;
  if (angle2 == 195) sdtcoxa = angle2;
  if (angle2 < 195) sdtcoxa = angle2 - lebar;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 72; //71

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 146; //139
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

//false = geser, true = maju
void FL2 (float x, float y, float h, float lebar) { //105
  z = height + h;
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  angle2 = round(angle1 - legoffset[1]) + 19; //18

  if (arahgerak == true) {
    if (angle2 > 105) sdtcoxa = angle2 - lebar;
    if (angle2 < 105) sdtcoxa = angle2 + lebar;
    if (angle2 == 105) sdtcoxa = angle2;
  }
  if (arahgerak == false) {
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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 76; //74

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 161; //146
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BL2 (float x, float y, float h, float lebar) { //19
  z = height2 + h;
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  angle2 = round(angle1 - legoffset[2]) + 24; //10

  if (angle2 < 195) sdtcoxa = angle2 + lebar;
  if (angle2 > 195) sdtcoxa = angle2 - lebar;
  if (angle2 == 195) sdtcoxa = angle2;

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));

  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 71; //72

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 166; //149
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BR2 (float x, float y, float h, float lebar) { //105
  z = height2 + h;
  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
  angle2 = round(angle1 - legoffset[3]) + 16; //15

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
  sdtfemur = 90 + round ((theta2 * 57.296)) + 68; //72

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 142; //138
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}
