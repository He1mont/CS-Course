% Matrix Size [PROBLEM 3 (a)]

function [m,n]=matSize(X)

clc
m=0;
n=0;
R=X(1,:); % copy the first row of X into R
C=X(:,1); % copy the first column of X into C

while ~isempty(R)
    n=n+1; % count number of elements
    R(1)=[]; % delete elements until R becomes empty
end
while ~isempty(C)
    m=m+1;
    C(1)=[];
    
end

