create or replace function increase_salary() returns void as
$$
declare
    salary CURSOR for select * from cursor_salary;
    each_row RECORD;
    s int;
begin
    OPEN salary;
    LOOP
       FETCH salary into each_row;
       EXIT WHEN NOT FOUND;
       s:=each_row.m_salary;
       if s<60000 then
            update cursor_salary set m_salary=(0.25*s+s) where id=each_row.id;
       elsif s>=60000 and s<200000 then
             update cursor_salary set m_salary=(0.20*s+s) where id=each_row.id;
       elsif s>=200000 and s<500000 then
             update cursor_salary set m_salary=(0.15*s+s) where id=each_row.id;
       elsif s>=500000 then
             update cursor_salary set m_salary=(0.10*s+s) where id=each_row.id;
       end if;
    END LOOP;
    CLOSE salary;
end;
$$ language plpgsql;
