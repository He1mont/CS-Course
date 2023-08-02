% Performs integer division. q=qoutient; r=remainder
function [q,r]=intDiv(x,y)
q=0;
while x>=y
    x=x-y;
    q=q+1;
end
r=x;
