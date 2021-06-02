create table driver(
	id_driver serial primary key,
	firstLast varchar ,
	passport_num int ,
	driver_document int ,
	category varchar
);

create table vehicle(
	id_vehicle serial not null primary key,
	id_driver serial not null,
	vehicle_amount int not null,
	release_time int not null,
	state_num varchar not null,
	vin varchar not null,
	foreign key (id_driver) references driver(id_driver)
);

create table destination(
    id_destination serial not null primary key,
	firstLast_dst varchar not null,
	phone_number varchar not null,
	id_dealAgreement serial not null,
	document_type varchar not null,
	product_sum int not null,
    foreign key (id_dealAgreement) references destination(id_destination)
);

create table route_sheet(
    id_routeSheet serial not null primary key,
	id_vehicle serial not null,
	id_destination serial not null,
	organisation varchar not null,
	reason varchar not null,
	time_stamp varchar not null,
	foreign key (id_vehicle) references vehicle(id_vehicle),
	foreign key (id_destination) references destination(id_destination)
);

drop table destination cascade;
drop table route_sheet cascade;
drop table vehicle cascade;
drop table driver cascade;

insert into driver values(1, 'Aleen Mansfield', 11111, 22222, 'E');
insert into vehicle values(1, 1, 100, '1990', 'A00AA97', '2F4HL453CRG678102');
insert into destination values (1, 'Clayson Guerre', '662-399-2832', 1, 'Contract', 233);
insert into route_sheet values(1, 1, 1, 'Horns and hooves', 'Delivery', '9/10/2020');

insert into driver values(2, 'Nanette Kiehne', 33333, 44444, 'C');
insert into vehicle values(2, 2, 40, '1980', 'B00BB73', '6H4GD453CDS740571');
insert into destination values (2, 'Freddie Exeter', '622-345-5354', 2, 'Contract', 422);
insert into route_sheet values(2, 2, 2, 'Hooves', 'Delivery', '9/10/2019');

insert into driver values(3, 'Kelvin Capinetti', 55555, 66666, 'E');
insert into vehicle values(3, 3, 130, '1986', 'A00LL97', '3J4GD654TBS567518');
insert into destination values (3, 'Clayson Guerre', '662-399-2832', 3, 'Contract', 4563);
insert into route_sheet values(3, 3, 3, 'Horns and hooves', 'Delivery', '9/11/2016');

insert into driver values(4, 'Gene Fanshawe', 77777, 88888, 'E');
insert into vehicle values(4, 4, 20, '2013', 'A00KK97', '5D4GD563CDS735185');
insert into destination values (4, 'Beulah Marsters', '662-423-1234', 4, 'Contract', 2233);
insert into route_sheet values(4, 4, 4, 'Horns', 'Delivery', '29/12/2018');

insert into driver values(5, 'Serene Bowlesworth', 99999, 10101, 'C');
insert into vehicle values(5, 5, 660, '1995', 'P00PP97', '8M4GD345DTB053166');
insert into destination values (5, 'Beulah Marsters', '662-423-1234', 5, 'Contract', 23113);
insert into route_sheet values(5, 5, 5, 'Horns', 'Delivery', '19/9/2016');

truncate table driver cascade;
truncate table destination cascade;

--Второе задание, a:
--Использовать переменные после знака равно
select v.id_vehicle, v.vehicle_amount, case when vehicle_amount >= 200 then 'ok' when vehicle_amount <= 200 then 'not ok' end as amount_result, d.id_driver, d.category FROM driver d INNER JOIN vehicle v on v.id_driver=d.id_driver;

--Второе задание, b
create view driver_dstFI_view as select ro.id_routesheet, ro.organisation, v.id_vehicle, v.state_num from route_sheet ro
inner join vehicle v on ro.id_vehicle=v.id_vehicle;

drop view driver_dstFI_view;

select * from driver_dstFI_view order by organisation;

--Второе задание, c
select (select avg(dst.product_sum) from destination dst) as average_prod, (select count(dr.id_driver) from driver dr) as driver_count
from (select v.id_driver, v.vehicle_amount from vehicle v) as vi_amount inner join driver dr on dr.id_driver=vi_amount.id_driver
where (select avg(amount.vehicle_amount) from (select v.vehicle_amount from vehicle v where dr.id_driver=v.id_driver) as amount) > 220;

--Второе задание, d
select v.id_vehicle, sum(v.vehicle_amount) as vehicle_sum, ro.id_routesheet, ro.organisation, dr.id_driver, dr.driver_document from route_sheet ro inner join vehicle v on ro.id_vehicle=v.id_vehicle inner join driver dr on v.id_driver=dr.id_driver group by dr.driver_document, ro.organisation, v.id_vehicle,  ro.id_routesheet, dr.id_driver having sum(dr.driver_document)>20000;

--Второе задание, e
select ro.organisation, d.firstLast_dst from route_sheet ro inner join destination d on ro.id_destination=d.id_destination where  d.product_sum > all(select dr.driver_document from driver dr where dr.driver_document < 10);

--Третье задание
create index routeSheet_idx on route_sheet(time_stamp);

create index vehicle_idx on vehicle(vin);

select id_destination, organisation, time_stamp from route_sheet where time_stamp='29/12/2018';

select id_vehicle, vin from vehicle where vin='5D4GD563CDS735185';

drop index routeSheet_idx;

drop index vehicle_idx;

--Четвёртое задание
create function func()
returns trigger
as $$
begin
update driver set summing_data = passport_num + driver_document where id_driver=new.id_driver;
return new;
end;
$$ language plpgsql;

create trigger trigg after update on driver for each row
when  ((pg_trigger_depth()=0)) execute procedure func();

drop trigger trigg on driver;
drop function func();

update driver set passport_num=999 where id_driver=1;

select * from driver;

alter table driver add column summing_data integer;

alter table driver drop column summing_data;

--Пятое задание
--Для удаления, добавления и изменения данных в destination
create procedure del_destination(delete_id int)
as $$
begin
delete from destination dst where dst.id_destination=delete_id;
end;
$$ language plpgsql;

drop procedure del_destination;

call del_destination(6);

create procedure insert_destination(ins_id int, ins_firstLast_dst varchar, ins_phone_number varchar,
								   ins_dealAgreement_id int, ins_document_type varchar,
								   ins_product_sum int)
as $$
begin
insert into destination values (ins_id, ins_firstLast_dst, ins_phone_number,
								   ins_dealAgreement_id, ins_document_type,
								   ins_product_sum);
end;
$$ language plpgsql;

call insert_destination(6, 'q', '3', 6, '3', 'e');

drop  procedure insert_destination;

create procedure update_destination(upd_id int, upd_firstLast_dst varchar, upd_phone_number varchar,
								   upd_dealAgreement_id int, upd_document_type varchar,
								   upd_product_sum int)
as $$
begin
update destination set  firstLast_dst=upd_firstLast_dst,
phone_number=upd_phone_number,  id_dealAgreement=upd_dealAgreement_id,
document_type=upd_document_type, product_sum=upd_product_sum where id_destination=upd_id;
end;
$$ language plpgsql;

drop procedure update_destination;

call update_destination(1, 's', 's', 1, 'sd', 23);

--Для удаления, добавления и изменения данных в route_sheet
create procedure del_routesheet(delete_id int)
as $$
begin
delete from route_sheet ro where ro.id_routesheet=delete_id;
end;
$$ language plpgsql;

create procedure insert_routesheet(ins_id int, ins_vehicle_id int, ins_destination_id int,
								   ins_organisation varchar, ins_reason varchar,
								   ins_timestamp varchar)
as $$
begin
insert into route_sheet values (ins_id, ins_vehicle_id, ins_destination_id,
								   ins_organisation, ins_reason,
								   ins_timestamp);
end;
$$ language plpgsql;

call insert_routesheet(6,3,3,'q','q','q');

drop procedure  insert_routesheet;

create procedure update_routesheet(upd_id int, upd_vehicle_id int, upd_destination_id int,
								   upd_oragnisation varchar, upd_reasaon varchar,
								   upd_timestamp varchar)
as $$
begin
update route_sheet set id_vehicle=upd_vehicle_id,
id_destination=upd_destination_id,  organisation=upd_oragnisation,
reason=upd_reasaon, time_stamp=upd_timestamp where id_routesheet=upd_id;
end;
$$ language plpgsql;

call update_routesheet(5, 2,2 ,'sd', 'ds', 'ds');

drop procedure update_routesheet;

select * from route_sheet;
--Для удаления, добавления и изменения данных в driver
create procedure del_driver(delete_id int)
as $$
begin
delete from driver dr where dr.id_driver=delete_id;
end;
$$ language plpgsql;

create procedure insert_driver(ins_id int, ins_firstlast varchar, ins_passportNum int,
								   ins_driverDocument int, ins_category varchar)
as $$
begin
insert into driver values (ins_id, ins_firstlast, ins_passportNum,
								   ins_driverDocument, ins_category);
end;
$$ language plpgsql;

create procedure update_driver(upd_id int, upd_firstlast varchar, upd_passportNum int,
								   upd_driverDocument int, upd_category varchar)
as $$
begin
update driver set firstlast=upd_firstlast,
passport_num=upd_passportNum,  driver_document=upd_driverDocument,
category=upd_category where id_driver=upd_id;
end;
$$ language plpgsql;

call update_driver(5,'s', 232, 3232, 'as');

--Для удаления, добавления и изменения данных в vehicle
create procedure del_vehicle(delete_id int)
as $$
begin
delete from vehicle v where v.id_vehicle=delete_id;
end;
$$ language plpgsql;

call del_vehicle(6);

drop procedure del_vehicle;

create procedure insert_vehicle(ins_id int, ins_driver_id int, ins_vehicleAmount int,
								   ins_releaseTime varchar, ins_stateNum varchar,
								   ins_vin varchar)
as $$
begin
insert into vehicle values (ins_id, ins_driver_id, ins_vehicleAmount,
								   ins_releaseTime, ins_stateNum,
								   ins_vin);
end;
$$ language plpgsql;

call insert_vehicle(6,5,6456,'asds', 'add','asd');

drop procedure insert_vehicle;

create procedure update_vehicle(upd_id int, upd_driver_id int, upd_vehicleAmount int,
								   upd_releaseTime varchar, upd_stateNum varchar,
								   upd_vin varchar)
as $$
begin
update vehicle set id_driver=upd_driver_id,
vehicle_amount=upd_vehicleAmount,  release_time=upd_releaseTime,
state_num=upd_stateNum, vin=upd_vin where id_vehicle=upd_id;
end;
$$ language plpgsql;

call update_vehicle(5,5,660,'1995', 'P00PP97','8M4GD345DTB053166');

drop procedure update_vehicle;

--Шестое задание
create procedure _transtction()
as $$
    declare max_value int;
begin
    max_value = (select max(vehicle_amount) from vehicle);
if (select max_value from vehicle) < 100 then
    update vehicle set vehicle_amount = 0 where id_vehicle>0;
rollback;
else
    update vehicle set vehicle_amount = 999 where id_vehicle>0;
commit;
end if;
end;
$$ language plpgsql;

call _transtction();

drop procedure _transtction();

select  * from vehicle;

--Седьмое задание

create procedure curs_procedure()
as $$
declare
    _cursor cursor for select firstLast_dst, phone_number from destination;
    _record record;
begin
    open _cursor;
    loop
        fetch _cursor into _record;
        exit when not FOUND;
        update destination set firstLast_dst=_record.firstlast_dst;
    end loop;
    close _cursor;
end;
$$ language plpgsql;

call curs_procedure();

select * from destination;

drop procedure curs_procedure();

--Восьмое задание
create function seek_certain_passport(id_pass int)
returns int
as $$
    declare pass_num int;
begin
select passport_num into pass_num from driver where id_driver = id_pass;
    return pass_num;
end;
$$ language plpgsql;

drop function  seek_certain_passport(id_pass int);

select  seek_certain_passport(1) from driver;

create function seek_certain_driver_doc()
returns table (id_driv int, fl varchar)
as $$
begin
    return query
    select id_driver, firstlast from driver where driver_document%2=0;
end;
$$ language plpgsql;

drop function seek_certain_driver_doc();

select * from seek_certain_driver_doc() where id_driv%2=0;

--Девятое задание
create role privileged_role login;
create role regular_role login;

grant connect on database test to privileged_role;
grant connect on database test to regular_role;
grant select, update, insert, delete on destination, driver, vehicle, route_sheet, driver_dstFI_view  to privileged_role;
grant select, insert on destination, driver, route_sheet, vehicle, driver_dstFI_view  to regular_role;
create user _admin password 'admin';
create user _user password '0000';
grant  privileged_role to _admin;
grant regular_role to _user;

drop user _admin;
drop user _user;

drop owned by privileged_role;
drop owned by regular_role;

drop role privileged_role;
drop role regular_role;


