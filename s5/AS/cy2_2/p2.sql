create or replace function add_interest() returns void as 
$$
declare 
    bank CURSOR for select * from cursor_bank;
    each_row RECORD;
    interest int;
begin
    OPEN bank;
    LOOP
        FETCH bank into each_row;
        EXIT WHEN NOT FOUND;
        interest:=0.08*each_row.balance;
        insert into cursor_bank_interest values(each_row.accno,interest);
    END LOOP;
    CLOSE bank;
end;
$$ language plpgsql;
