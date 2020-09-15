create or replace function circle_arr(text) returns void as
$$
declare
    r int[];
    i int;
    a int;
begin
    r=string_to_array($1,',');
    for i in 0..5 loop
        a=3.14*r[i]*r[i];
        insert into circle values(r[i],a);
    end loop;
end;
$$ language plpgsql;
