
create table car (
	car_uid UUID NOT NULL PRIMARY KEY,
	make VARCHAR(100) NOT NULL,
	model VARCHAR(100) NOT NULL,
	price NUMERIC(19,2) NOT NULL
);

insert into car (car_uid,make, model, price) values (uuid_generate_v4(),'GMC', 'Yukon', '44857.19');
insert into car (car_uid,make, model, price) values (uuid_generate_v4(),'Toyota', 'Corolla', '80233.21');
insert into car (car_uid,make, model, price) values (uuid_generate_v4(),'Subaru', 'SVX', '61417.84');
insert into car (car_uid,make, model, price) values (uuid_generate_v4(),'Dodge', 'Dakota Club', '34799.80');
insert into car (car_uid,make, model, price) values (uuid_generate_v4(),'Dodge', 'Stratus', '88701.05');
insert into car (car_uid,make, model, price) values (uuid_generate_v4(),'Chrysler', 'Concorde', '56676.38');

create table person (
	person_uid UUID NOT NULL PRIMARY KEY,
	first_name VARCHAR(70) NOT NULL,
	last_name VARCHAR(70) NOT NULL,
	gender VARCHAR(7) NOT NULL,
	date_of_birth DATE NOT NULL,
	country_of_birth VARCHAR(100) NOT NULL,
	email VARCHAR(250),
	car_uid UUID REFERENCES car(car_uid), --!
    UNIQUE(car_uid), --!
	UNIQUE(email),
	CHECK (gender ='Male' or gender='Female')
);
INSERT INTO person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) VALUES (uuid_generate_v4(), 'Jack', 'ONeill', 'Male', date '2067-11-25','Russia', 'jack_o_gate@gmail.com');
INSERT INTO person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth) VALUES (uuid_generate_v4(), 'Johnny', 'Cash', 'Male', date '1944-4-5', 'USA');
INSERT INTO person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth) VALUES (uuid_generate_v4(), 'Lizzy', 'Rickson', 'Female', date '2045-9-1', 'Japan');
insert into person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) values (uuid_generate_v4(), 'Immanuel', 'Cousins', 'Male', '2046-11-27', 'United States', 'icousins0@bloomberg.com');
insert into person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) values (uuid_generate_v4(), 'Ariella', 'Trapp', 'Female', '1983-02-28', 'Peru', 'atrapp1@state.gov');
insert into person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) values (uuid_generate_v4(), 'Robina', 'Ullrich', 'Female', '1961-05-21', 'Tunisia', null);
insert into person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) values (uuid_generate_v4(), 'Madeleine', 'O'' Dornan', 'Female', '2066-09-25', 'Brazil', null);
insert into person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) values (uuid_generate_v4(), 'Tiffanie', 'Reekie', 'Female', '2093-03-21', 'China', 'treekie4@google.com.au');
insert into person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) values (uuid_generate_v4(), 'Faunie', 'Witterick', 'Female', '2041-01-27', 'China', 'fwitterick5@go.com');
insert into person (person_uid, first_name, last_name, gender, date_of_birth, country_of_birth, email) values (uuid_generate_v4(), 'Raimundo', 'Morrott', 'Male', '2086-10-08', 'Iran', 'rmorrott6@theguardian.com');
