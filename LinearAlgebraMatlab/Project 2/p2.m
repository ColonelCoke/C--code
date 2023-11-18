%Orion Gregory
2.1 - 2.3
codingA = [1 2 1; 2 5 -1; 1 2 0;];
V = [8 5 12 12 15 27 23 15 18 12 4 ];
matrixV = [8 12 23 12; 5 15 15 4; 12 27 18 27;];
matrixComplete =codingA*matrixV;
str = mat2str(matrixComplete);

2.a - 2.c
codingB = [1 -3 1 -2; 2 -5 4 -2; -3 9 -2 5; 4 -12 4 -7;];
codeMessage = [9 27 12 15 22 5 27 12 9 14 5 1 18 27 1 12 7 5 2 18 1 27 27 27];
codeMessageMatrix = reshape(codeMessage, 4, []);
encodedMessage = codingB * codeMessageMatrix;

mm1 = [16 91 -31 69 -92 -81 272 -347 -50 -23 161 -191 -62 -18 178 -221 -40 28 127 -140 -86 -59 251 -317 -88 -69 252 -325];
mm1Matrix = reshape(mm1, 4, []);
uncodedMessage = inv(codingB) *  mm1Matrix;
mm2 = [-48, -58, 131, -178, -11, 67, 45, -29, -75, -117, 226, -299, -43, 15, 121, -145, -80, -97, 223, -301, 6, 29, -20, 29, -19, 5, 39, -57, -103, -71, 309, -385];
mm2Matrix = reshape(mm2, 4, []);
uncodedMessage1 = inv(codingB) * mm2Matrix;

C = [6 2 0 1; 3 1 0 2; 0 3 2 0; 0 0 0 -7];
int = det(C);
