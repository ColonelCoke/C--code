a = 15;
(2.2 * a) - 3;
b = exp(4);
pi;
c = b/a;
a = b + 16*pi;

a = [2 2 3 4 5; 6 1 2 0 7; -4 2 -1 3 4];
b = [3; 5; 14;];
c = [a b];

d = c(3,5); 
e = c(2, :);
f = c(:,2);
g=c(:,[1 3 5]);
c([1 3],:) = c([3 1],:);
c(3,:) = 5 * c(3,:);
c(3, :) = c(3, :) + (−c(3, 1)/c(1, 1)) ∗ c(1, :);
zeros(5, 2);
eye(6);

amatrix = [2 2 3 4 5; 6 1 2 0 7; -4 2 -1 3 4];
a = amatrix(2,1);
temp1 = a;
amatrix(3,:);
amatrix([1 3],:) = amatrix([3 1],:);
temp2 = c;
c(:,3);
c(:,4) = c(:,4) * 2;
c(:, [2 5]) = c(:, [5 2]);
amatrix(2, :) = amatrix(2, :) + (-amatrix(2, 1)/amatrix(1, 1)) * amatrix(1, :);
h = c(:,[1 2 5 6]);
matrixtemp = [2 4 9 -5 2 -3; 1 2 4 -1 2 1; -3 -6 -14 9 -3 14];
rref(matrixtemp);