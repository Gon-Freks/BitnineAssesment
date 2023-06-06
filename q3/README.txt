The development environment:
Ubuntu 20.04.2 LTS
NodeJS v16.17.0
pg package ^8.11.0

How to get started:
- head to the q3 folder and run `npm install` to install the dependencies.
- open a terminal and run `sudo service postgresql start` to start the postgresql service.
- run `psql -U postgres`
- change the password for the postgres user by running ALTER USER postgres WITH PASSWORD '1234';
- make the following query to create a dummy table:

```
CREATE TABLE IF NOT EXISTS public.user_table
(
  user_id numeric(10,0) NOT NULL,
  name character varying(50) COLLATE pg_catalog."default" NOT NULL,
  age numeric(3,0) NOT NULL,
  phone character varying(20) COLLATE pg_catalog."default",
  CONSTRAINT user_table_pkey PRIMARY KEY (user_id)
);

INSERT INTO public.user_table (user_id, name, age, phone)
VALUES (3, 'Jenny', 34, NULL);

INSERT INTO public.user_table (user_id, name, age, phone)
VALUES (2, 'Tom', 29, '1-800-123-1234');

INSERT INTO public.user_table (user_id, name, age, phone)
VALUES (1, 'John', 28, NULL);
```
- enter `\q` to exit the psql shell.
- run `node index.js` to start the server.
- the server will run the following query
```
SELECT * FROM public.user_table;
```

- the output in the terminal will be as following:
Result: {"status_code":200,"data":[{"user_id":"3","name":"Jenny","age":"34","phone":null},{"user_id":"2","name":"Tom","age":"29","phone":"1-800-123-1234"},{"user_id":"1","name":"John","age":"28","phone":null}]}

