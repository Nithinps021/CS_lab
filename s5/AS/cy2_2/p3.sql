create or replace function find_experience() returns void as
$$
declare
    people CURSOR for select id,name,DATE_PART('year',AGE(now(),dt_join)) as experience from cursor_people;
    each_row RECORD;
begin
    OPEN people;
    LOOP
        FETCH people into each_row;
        EXIT WHEN NOT FOUND;
        if each_row.experience >10 then
            insert into exp_list values(each_row.id,each_row.name,each_row.experience);
        end if;
    END LOOP;
    CLOSE people;
end;
$$ language plpgsql;
