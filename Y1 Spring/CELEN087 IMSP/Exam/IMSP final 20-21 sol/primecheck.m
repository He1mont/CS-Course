
function primecheck(p)
clc
reply='Y';

while reply == 'Y'
    X=primelist(p,p+1); % OR ==> X=primelist(p-1,p);

    if isempty(X)
        sprintf('The number %d is NOT prime.',p)
    else
        if X==p
            sprintf('The number %d is prime.',p)
        else
            sprintf('The number %d is NOT prime.',p)
        end
    end
    
    reply = input('Would you like to check another number [Y/N]: ','s');
    if reply=='Y'
        p=input('Enter another integer: ');
    end

end
