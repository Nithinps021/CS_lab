create or replace function sequ(text,int) returns void as
$$
declare
    n text[];
begin
    n=string_to_array($1,',');
    
    create sequence sq4
    increment  1
    minvalue 100
    maxvalue 999
    start 101
    cycle;
    
    for i in 1..($2) loop
        insert into seqP6 values(nextval('sq4'),n[i]);
    end loop;
end;
$$ language plpgsql;
