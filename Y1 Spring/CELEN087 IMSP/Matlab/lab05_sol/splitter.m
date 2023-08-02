
% splitter.m
clc
clear
response='Y';
while response=='Y'
    clc
    X=input('Enter a square matrix > 3x3: ');
    [U,D,L]=splitMat(X);

    % Print the message
    disp(' ')
    disp('The Lower-Trangular matrix L is:')
    disp(L)
    disp(' ')
    disp('The Upper-Trangular matrix U is:')
    disp(U)
    disp(' ')
    disp('The Diagonal matrix D is:')
    disp(D)
    
    response=input('Would you like to try again? [Y/N]: ','s');
end