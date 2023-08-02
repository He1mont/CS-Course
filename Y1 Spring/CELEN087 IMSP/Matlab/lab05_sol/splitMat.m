
%% splitMat functions splits an nxn matrix to U, L and D

function [A,B,C]=splitMat(X)

n=size(X,1); % dimensions of X
A=zeros(n);
B=zeros(n);
C=zeros(n);

for i=1:n % rows
    for j=1:n % columns    
        if i>j
            C(i,j)=X(i,j);
        elseif i==j
            B(i,j)=X(i,j);
        else
            A(i,j)=X(i,j);
        end     
    end
end

