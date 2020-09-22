create or replace function prime(a int) returns void as
$$
declare
    c int :=1;
    i int :=3;
    f int :=1;
    l int;
begin
    raise notice '%',2;
    while c != a loop
        f:=1;
        for l in 3..i/2 by 2 loop
            if i%l=0 then
                f:=0;
                EXIT;
            end if;
        end loop;
        if f=1 then
            c:=c+1;
            raise notice '%',i;
        end if;
        i:=i+2;
    end loop;
end;
$$language plpgsql;
