create or replace function fibno(n int) returns void as
$$
declare
    a int:=0;
    b int:=1;
    c int;
    cn int:=2;
begin
    raise notice '%',0;
    raise notice '%',1;
    while cn!=n loop
        c:=a+b;
        raise notice '%',c;
        a:=b;
        b:=c;
        cn:=cn+1;
    end loop;
end;
$$ language plpgsql;
