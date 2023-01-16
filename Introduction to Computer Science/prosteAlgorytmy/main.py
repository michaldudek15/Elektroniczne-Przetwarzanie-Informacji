while p do
    [ ]
od




repeat
    [ ]
until
    q



while (p) [ ]




while p:
    [ ]



begin
    read element(int)
    for i = 1 ; i < n ; i++
        if T[i] = element
            for j = i ; j < n-1 ; j++
                T[j] <- T[j+1]
            T[n] <- null
        fi
end





ZADANIE 33
T = [2, 4, 7, 5 ,3 ,5], n = 6

begin
    read element(int)
    i <- 1
    while i < n do
        if T[i] = element then
            j <- i
            while j < n do
                T[j] = T[j+1];
                j += 1;
            od
            T[n] <- null;
        fi
        i += 1;
    od
end




