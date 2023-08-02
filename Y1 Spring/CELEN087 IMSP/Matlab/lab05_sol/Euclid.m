
function d=Euclid(a,b)

[q,r]=intDiv(a,b);
while r>0
    a=b;
    b=r;
    [q,r]=intDiv(a,b);    
end
d=b;