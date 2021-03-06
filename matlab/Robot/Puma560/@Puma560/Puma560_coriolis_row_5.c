#include "Puma560_coriolis_row_5.h"

void Puma560_coriolis_row_5(double C_row_5[][1], const double* input1, const double* input2){
 
  double q1 = input1[0];
  double q2 = input1[1];
  double q3 = input1[2];
  double q4 = input1[3];
  double q5 = input1[4];
  double q6 = input1[5];
  double qd1 = input2[0];
  double qd2 = input2[1];
  double qd3 = input2[2];
  double qd4 = input2[3];
  double qd5 = input2[4];
  double qd6 = input2[5];
 
       C_row_5[0][0]=0;
 C_row_5[1][0]=0;
 C_row_5[2][0]=0;
 C_row_5[3][0]=0;
 C_row_5[4][0]=0;
 C_row_5[5][0]=0;



  C_row_5[0][0] = qd1*sin(q5*2.0)*(-1.0108E-4)+qd1*cos(q4)*cos(q5)*5.8464E-5-qd1*cos(q5)*sin(q4)*4.32144E-4+qd1*pow(cos(q2),2.0)*sin(q5)*1.243584E-3+qd1*pow(cos(q3),2.0)*sin(q5)*1.243584E-3-qd1*pow(cos(q2),2.0)*pow(cos(q3),2.0)*sin(q5)*2.487168E-3-qd1*cos(q2)*cos(q4)*sin(q2)*2.0216E-4-qd1*cos(q3)*cos(q4)*sin(q3)*2.0216E-4+qd2*cos(q2)*cos(q3)*sin(q4)*2.2E-4+qd3*cos(q2)*cos(q3)*sin(q4)*2.2E-4+qd4*cos(q2)*cos(q4)*sin(q3)*4.2216E-4+qd4*cos(q3)*cos(q4)*sin(q2)*4.2216E-4+qd6*cos(q2)*cos(q3)*sin(q5)*2.0E-5+qd1*cos(q2)*sin(q2)*sin(q5)*5.8464E-5+qd1*cos(q3)*sin(q3)*sin(q5)*5.8464E-5+qd2*cos(q5)*sin(q2)*sin(q4)*1.243584E-3-qd2*sin(q2)*sin(q3)*sin(q4)*2.2E-4-qd3*sin(q2)*sin(q3)*sin(q4)*2.2E-4-qd6*sin(q2)*sin(q3)*sin(q5)*2.0E-5-qd1*pow(cos(q2),2.0)*cos(q4)*cos(q5)*5.8464E-5-qd1*pow(cos(q3),2.0)*cos(q4)*cos(q5)*5.8464E-5+qd1*pow(cos(q2),2.0)*cos(q5)*sin(q5)*2.0216E-4+qd1*pow(cos(q3),2.0)*cos(q5)*sin(q5)*2.0216E-4-qd1*pow(cos(q2),2.0)*sin(q3)*sin(q5)*1.243584E-3+qd1*cos(q2)*cos(q4)*cos(q5)*sin(q2)*1.243584E-3+qd1*cos(q3)*cos(q4)*cos(q5)*sin(q3)*1.243584E-3+qd2*cos(q2)*cos(q3)*cos(q5)*sin(q4)*1.243584E-3+qd3*cos(q2)*cos(q3)*cos(q5)*sin(q4)*1.243584E-3-qd4*cos(q2)*cos(q3)*cos(q5)*sin(q5)*2.0216E-4+qd6*cos(q2)*cos(q4)*cos(q5)*sin(q3)*2.0E-5+qd6*cos(q3)*cos(q4)*cos(q5)*sin(q2)*2.0E-5-qd1*cos(q2)*cos(q3)*sin(q2)*sin(q5)*1.243584E-3+qd2*cos(q2)*cos(q5)*sin(q3)*sin(q4)*5.8464E-5+qd2*cos(q3)*cos(q5)*sin(q2)*sin(q4)*5.8464E-5+qd3*cos(q2)*cos(q5)*sin(q3)*sin(q4)*5.8464E-5+qd3*cos(q3)*cos(q5)*sin(q2)*sin(q4)*5.8464E-5-qd2*cos(q5)*sin(q2)*sin(q3)*sin(q4)*1.243584E-3-qd3*cos(q5)*sin(q2)*sin(q3)*sin(q4)*1.243584E-3+qd4*cos(q5)*sin(q2)*sin(q3)*sin(q5)*2.0216E-4+qd1*pow(cos(q2),2.0)*cos(q3)*cos(q4)*cos(q5)*1.243584E-3+qd1*cos(q2)*pow(cos(q3),2.0)*cos(q4)*sin(q2)*4.0432E-4+qd1*pow(cos(q2),2.0)*cos(q3)*cos(q4)*sin(q3)*4.0432E-4+qd1*cos(q2)*cos(q4)*pow(cos(q5),2.0)*sin(q2)*4.0432E-4+qd1*cos(q3)*cos(q4)*pow(cos(q5),2.0)*sin(q3)*4.0432E-4+qd2*cos(q2)*cos(q3)*pow(cos(q5),2.0)*sin(q4)*2.0216E-4+qd3*cos(q2)*cos(q3)*pow(cos(q5),2.0)*sin(q4)*2.0216E-4-qd4*cos(q2)*cos(q4)*pow(cos(q5),2.0)*sin(q3)*2.0216E-4-qd4*cos(q3)*cos(q4)*pow(cos(q5),2.0)*sin(q2)*2.0216E-4-qd1*cos(q2)*pow(cos(q3),2.0)*sin(q2)*sin(q5)*1.16928E-4-qd1*pow(cos(q2),2.0)*cos(q3)*sin(q3)*sin(q5)*1.16928E-4-qd2*pow(cos(q5),2.0)*sin(q2)*sin(q3)*sin(q4)*2.0216E-4-qd3*pow(cos(q5),2.0)*sin(q2)*sin(q3)*sin(q4)*2.0216E-4+qd1*pow(cos(q2),2.0)*pow(cos(q3),2.0)*cos(q4)*cos(q5)*1.16928E-4-qd1*pow(cos(q2),2.0)*pow(cos(q3),2.0)*cos(q5)*sin(q5)*4.0432E-4+qd1*pow(cos(q2),2.0)*pow(cos(q4),2.0)*cos(q5)*sin(q5)*2.0216E-4+qd1*pow(cos(q3),2.0)*pow(cos(q4),2.0)*cos(q5)*sin(q5)*2.0216E-4-qd1*cos(q2)*cos(q4)*cos(q5)*sin(q2)*sin(q3)*1.243584E-3-qd1*pow(cos(q2),2.0)*pow(cos(q3),2.0)*pow(cos(q4),2.0)*cos(q5)*sin(q5)*4.0432E-4+qd1*cos(q2)*cos(q3)*sin(q2)*sin(q3)*sin(q5)*2.487168E-3-qd1*cos(q2)*pow(cos(q3),2.0)*cos(q4)*cos(q5)*sin(q2)*2.487168E-3-qd1*pow(cos(q2),2.0)*cos(q3)*cos(q4)*cos(q5)*sin(q3)*2.487168E-3-qd1*cos(q2)*pow(cos(q3),2.0)*cos(q4)*pow(cos(q5),2.0)*sin(q2)*8.0864E-4-qd1*pow(cos(q2),2.0)*cos(q3)*cos(q4)*pow(cos(q5),2.0)*sin(q3)*8.0864E-4-qd1*cos(q2)*cos(q3)*cos(q4)*cos(q5)*sin(q2)*sin(q3)*1.16928E-4+qd1*cos(q2)*cos(q3)*cos(q5)*sin(q2)*sin(q3)*sin(q5)*4.0432E-4-qd2*cos(q2)*cos(q4)*cos(q5)*sin(q3)*sin(q4)*sin(q5)*2.0216E-4-qd2*cos(q3)*cos(q4)*cos(q5)*sin(q2)*sin(q4)*sin(q5)*2.0216E-4-qd3*cos(q2)*cos(q4)*cos(q5)*sin(q3)*sin(q4)*sin(q5)*2.0216E-4-qd3*cos(q3)*cos(q4)*cos(q5)*sin(q2)*sin(q4)*sin(q5)*2.0216E-4+qd1*cos(q2)*cos(q3)*pow(cos(q4),2.0)*cos(q5)*sin(q2)*sin(q3)*sin(q5)*4.0432E-4;
  C_row_5[1][0] = qd2*sin(q5*2.0)*1.0108E-4+qd3*sin(q5*2.0)*1.0108E-4+qd2*sin(q5)*1.243584E-3+qd3*sin(q5)*1.243584E-3-qd4*sin(q4)*4.2216E-4+qd2*cos(q4)*cos(q5)*5.8464E-5+qd3*cos(q4)*cos(q5)*5.8464E-5-qd6*cos(q5)*sin(q4)*2.0E-5-qd2*sin(q3)*sin(q5)*1.243584E-3+qd4*pow(cos(q5),2.0)*sin(q4)*2.0216E-4+qd2*cos(q3)*cos(q4)*cos(q5)*1.243584E-3+qd1*cos(q2)*cos(q3)*sin(q4)*2.2E-4+qd1*cos(q5)*sin(q2)*sin(q4)*1.243584E-3-qd1*sin(q2)*sin(q3)*sin(q4)*2.2E-4-qd2*pow(cos(q4),2.0)*cos(q5)*sin(q5)*2.0216E-4-qd3*pow(cos(q4),2.0)*cos(q5)*sin(q5)*2.0216E-4+qd1*cos(q2)*cos(q3)*cos(q5)*sin(q4)*1.243584E-3+qd1*cos(q2)*cos(q5)*sin(q3)*sin(q4)*5.8464E-5+qd1*cos(q3)*cos(q5)*sin(q2)*sin(q4)*5.8464E-5-qd1*cos(q5)*sin(q2)*sin(q3)*sin(q4)*1.243584E-3+qd1*cos(q2)*cos(q3)*pow(cos(q5),2.0)*sin(q4)*2.0216E-4-qd1*pow(cos(q5),2.0)*sin(q2)*sin(q3)*sin(q4)*2.0216E-4-qd1*cos(q2)*cos(q4)*cos(q5)*sin(q3)*sin(q4)*sin(q5)*2.0216E-4-qd1*cos(q3)*cos(q4)*cos(q5)*sin(q2)*sin(q4)*sin(q5)*2.0216E-4;
  C_row_5[2][0] = qd2*sin(q5*2.0)*1.0108E-4+qd3*sin(q5*2.0)*1.0108E-4+qd2*sin(q5)*1.243584E-3+qd3*sin(q5)*1.243584E-3-qd4*sin(q4)*4.2216E-4+qd2*cos(q4)*cos(q5)*5.8464E-5+qd3*cos(q4)*cos(q5)*5.8464E-5-qd6*cos(q5)*sin(q4)*2.0E-5+qd4*pow(cos(q5),2.0)*sin(q4)*2.0216E-4+qd1*cos(q2)*cos(q3)*sin(q4)*2.2E-4-qd1*sin(q2)*sin(q3)*sin(q4)*2.2E-4-qd2*pow(cos(q4),2.0)*cos(q5)*sin(q5)*2.0216E-4-qd3*pow(cos(q4),2.0)*cos(q5)*sin(q5)*2.0216E-4+qd1*cos(q2)*cos(q3)*cos(q5)*sin(q4)*1.243584E-3+qd1*cos(q2)*cos(q5)*sin(q3)*sin(q4)*5.8464E-5+qd1*cos(q3)*cos(q5)*sin(q2)*sin(q4)*5.8464E-5-qd1*cos(q5)*sin(q2)*sin(q3)*sin(q4)*1.243584E-3+qd1*cos(q2)*cos(q3)*pow(cos(q5),2.0)*sin(q4)*2.0216E-4-qd1*pow(cos(q5),2.0)*sin(q2)*sin(q3)*sin(q4)*2.0216E-4-qd1*cos(q2)*cos(q4)*cos(q5)*sin(q3)*sin(q4)*sin(q5)*2.0216E-4-qd1*cos(q3)*cos(q4)*cos(q5)*sin(q2)*sin(q4)*sin(q5)*2.0216E-4;
  C_row_5[3][0] = qd4*sin(q5*2.0)*(-1.0108E-4)-qd2*sin(q4)*4.2216E-4-qd3*sin(q4)*4.2216E-4+qd6*sin(q5)*2.0E-5+qd2*pow(cos(q5),2.0)*sin(q4)*2.0216E-4+qd3*pow(cos(q5),2.0)*sin(q4)*2.0216E-4+qd1*cos(q2)*cos(q4)*sin(q3)*4.2216E-4+qd1*cos(q3)*cos(q4)*sin(q2)*4.2216E-4-qd1*cos(q2)*cos(q3)*cos(q5)*sin(q5)*2.0216E-4+qd1*cos(q5)*sin(q2)*sin(q3)*sin(q5)*2.0216E-4-qd1*cos(q2)*cos(q4)*pow(cos(q5),2.0)*sin(q3)*2.0216E-4-qd1*cos(q3)*cos(q4)*pow(cos(q5),2.0)*sin(q2)*2.0216E-4;
  C_row_5[5][0] = qd4*sin(q5)*2.0E-5-qd2*cos(q5)*sin(q4)*2.0E-5-qd3*cos(q5)*sin(q4)*2.0E-5+qd1*cos(q2)*cos(q3)*sin(q5)*2.0E-5-qd1*sin(q2)*sin(q3)*sin(q5)*2.0E-5+qd1*cos(q2)*cos(q4)*cos(q5)*sin(q3)*2.0E-5+qd1*cos(q3)*cos(q4)*cos(q5)*sin(q2)*2.0E-5;
}
 

