
create table car (
	id BIGSERIAL NOT NULL PRIMARY KEY,
	make VARCHAR(100) NOT NULL,
	model VARCHAR(100) NOT NULL,
	price NUMERIC(19,2) NOT NULL
);

insert into car (make, model, price) values ('GMC', 'Yukon', '44857.19');
insert into car (make, model, price) values ('Toyota', 'Corolla', '80233.21');
insert into car (make, model, price) values ('Subaru', 'SVX', '61417.84');
insert into car (make, model, price) values ('Dodge', 'Dakota Club', '34799.80');
insert into car (make, model, price) values ('Dodge', 'Stratus', '88701.05');
insert into car (make, model, price) values ('Chrysler', 'Concorde', '56676.38');

create table person (
	id BIGSERIAL NOT NULL PRIMARY KEY,
	first_name VARCHAR(70) NOT NULL,
	last_name VARCHAR(70) NOT NULL,
	gender VARCHAR(7) NOT NULL,
	date_of_birth DATE NOT NULL,
	country_of_birth VARCHAR(100) NOT NULL,
	email VARCHAR(250),
	car_id BIGINT REFERENCES car(id), --!
    UNIQUE(car_id), --!
	UNIQUE(email),
	CHECK (gender ='Male' or gender='Female')
);
INSERT INTO person (first_name, last_name, gender, date_of_birth, country_of_birth, email, car_id) VALUES ('Jack', 'ONeill', 'Male', date '2067-11-25','Russia', 'jack_o_gate@gmail.com', 5);
INSERT INTO person (first_name, last_name, gender, date_of_birth, country_of_birth,car_id) VALUES ('Johnny', 'Cash', 'Male', date '1944-4-5', 'USA', 6);
INSERT INTO person (first_name, last_name, gender, date_of_birth, country_of_birth) VALUES ('Lizzy', 'Rickson', 'Female', date '2045-9-1', 'Japan');
insert into person (first_name, last_name, gender, date_of_birth, country_of_birth, email,car_id) values ('Immanuel', 'Cousins', 'Male', '2046-11-27', 'United States', 'icousins0@bloomberg.com', 3);
insert into person (first_name, last_name, gender, date_of_birth, country_of_birth, email) values ('Ariella', 'Trapp', 'Female', '1983-02-28', 'Peru', 'atrapp1@state.gov');
insert into person (first_name, last_name, gender, date_of_birth, country_of_birth, email) values ('Robina', 'Ullrich', 'Female', '1961-05-21', 'Tunisia', null);
insert into person (first_name, last_name, gender, date_of_birth, country_of_birth, email) values ('Madeleine', 'O'' Dornan', 'Female', '2066-09-25', 'Brazil', null);
insert into person (first_name, last_name, gender, date_of_birth, country_of_birth, email) values ('Tiffanie', 'Reekie', 'Female', '2093-03-21', 'China', 'treekie4@google.com.au');
insert into person (first_name, last_name, gender, date_of_birth, country_of_birth, email) values ('Faunie', 'Witterick', 'Female', '2041-01-27', 'China', 'fwitterick5@go.com');
insert into person (first_name, last_name, gender, date_of_birth, country_of_birth, email) values ('Raimundo', 'Morrott', 'Male', '2086-10-08', 'Iran', 'rmorrott6@theguardian.com');
