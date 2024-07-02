
function K=primedisp(p)
clc

Q=2:1:p; % list of integers from 2 to p
K=[];
i=0;

while Q(1)<sqrt(p)
    i=i+1;
    K(i)=Q(1);
    j=(mod(Q,Q(1))==0); %logical index array
    Q(j)=[]; % delete the composite numbers
end
K=[K,Q];