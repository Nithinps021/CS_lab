create or replace function add_grade() returns void as
$$
declare
    marks CURSOR for select * from cursor_student;
    each_row RECORD;
    percentage int;
begin
    OPEN marks;
    LOOP 
        percentage:=0;
        FETCH marks into each_row;
        EXIT WHEN NOT FOUND;
        percentage:=((each_row.m1+each_row.m2+each_row.m3)*100)/300;
        update cursor_student set grade=percentage where id=each_row.id;
    END LOOP;
    CLOSE marks;
end;
$$ language plpgsql;
