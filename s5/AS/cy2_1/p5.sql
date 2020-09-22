create or replace function Student_details(text,text) returns void as
$$
declare
    m int[];
    n text[];
begin
    n=string_to_array($1,',');
    m=string_to_array($2,',');
    for i in 0..10 loop
        insert into student_arr values(n[i],m[i]);
    end loop;
end;
$$ language plpgsql;
