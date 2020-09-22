create or replace function enterStudent(roll int,name char,mark1 numeric(2),mark2 numeric(2),mark3 numeric(2)) returns void as
$$
declare
    average int;
    grade text;
begin 
    average:=(mark1+mark2+mark3)/3;
    if average>40 then
        grade:='PASS';
    else
        grade:='FAIL';
    end if;
    insert into students values(roll,name,mark1,mark2,mark3,grade);
end;
$$ language plpgsql;
