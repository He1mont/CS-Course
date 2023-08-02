%% QUESTION 1
clc
X=10:10:1000;
Y=X.^2;
ssX=sqrt(sum(Y)); % square root of sum of squares
sprintf('The square root of sum of squares is: %0.5f',ssX)

%% QUESTION 2
clc
clear
V=ceil(1000*rand(1,100));
W=[]; % empty vector
U=[]; % empty vector
pause
for i=1:length(V)
    if mod(V(i),2)==0
       W=[W,V(i)]; % separating even integers
    else
        U=[U,V(i)]; % separating odd integers
    end
end

sprintf('There are %d even numbers',length(W))
sprintf('There are %d odd numbers',length(U))

%% QUESTION 3
clc
clear
n=input('Enter a positive integer n: ');
M=ceil(1000*rand(n)+1000); % an nxn matrix with integer random entries between 1000 and 2000
primeCount=0;
for i=1:n
    for j=1:n
        if isprime(M(i))
            primeCount=primeCount+1;
        end
    end
end
if primeCount==0
    sprintf('There are no prime numbers')
else
    sprintf('There are %d prime numbers', primeCount)
end

%% QUESTION 4
clc
clear
response='Y';
while response == 'Y'
    m=input('Enter the number of rows: ');
    n=input('Enter the number of columns: ');
    A=zeros(m,n); % Empty matrix

    for i=1:m
        for j=1:n
            if i<j
                A(i,j)=i/(i+j);
            elseif i==j
                A(i,j)=i*j;
            else
                A(i,j)=sqrt(i-j);
            end
        end
    end
    disp(A)
    response=input('Would you like to try again? [Y/N]','s');
end

%% QUESTION 5
clc
clear
xVal=[0,-1,1,3,-5];
yVal=[-1,2,0,-3,4];
dist=zeros(5); % a matrix of zeros
for i=1:5
    for j=1:5
        if i<j
            dist(i,j)=sqrt((xVal(i)-xVal(j))^2+(yVal(i)-yVal(j))^2);
        else
            dist(i,j)=dist(j,i); % symmetric matrix
        end
    end
end
disp(dist)

%% QUESTION 6
clc
clear
response='Y';
while response=='Y'
n=input('Enter n: ');
X=n*eye(n); % Diagonal Matrix
for i=1:n
    for j=1:n
        if i==j
            if i==1
                X(i,j+1)=n+1;
            elseif i==n
                X(i,j-1)=n-1;
            else
                X(i,j-1)=n-1;
                X(i,j+1)=n+1;
            end
        end
    end
end
disp(X)
response=input('Would you like to try again? [Y/N]','s');
end


%% QUESTION 7
clc
clear
n=input('Enter a positive integer n>1: ');
m=n;
while n>1
    n=n-1;
    m=m*n;
end
sprintf('n! = %d',m)


