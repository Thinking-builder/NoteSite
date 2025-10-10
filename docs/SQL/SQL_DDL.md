
# SQL Data Database Language

## Create DB

```SQL
CREATE DATABASE databasename;
```

## DROP DB

```SQL
DROP DATABASE databasename;
```

## BACKUP DB

The ``BACKUP DATABASE`` statement is used in SQL Server to create a full back up of an existing SQL database.

```SQL
BACKUP DATABASE db
TO DISK 'filepath';
```

+ A differential back up only backs up the parts of the database that have changed since the last full database backup.

```SQL
BACKUP DATABASE databasename
TO DISK = 'filepath'
WITH DIFFERENTIAL;
```

## CREATE TABLE

The `CREATE TABLE` statement is used to create a new table in a database.

```SQL
CREATE TABLE table_name(
    column1 datatype,
    column2 datatype,
    column3 datatype,
    ...
);
```

!!! Note "SQL Datatype"
    > Refer to [SQL Data Types for more details](https://www.w3schools.com/sql/sql_datatypes.asp)
    + Usual String DataType

    |Data Type|Description|
    |:---:|:---:|
    |`CHAR(size)`|A FIXED length string (can contain **letters, numbers, and special characters**). The size parameter specifies the column length in characters - **can be from 0 to 255**. Default is 1|
    |`VARCHAR(size`|A VARIABLE length string (can contain letters, numbers, and special characters). The size parameter specifies the maximum string length in characters - can be from 0 to 65535|
    |`TEXT(size)`|Holds a string with a maximum length of 65,535 bytes|
    |`LONGTEXT`|Holds a string with a maximum length of 4,294,967,295 characters|
    |`ENUM(val1,val2,val3,...)`|A string object that can have only one value, chosen from a list of possible values. You can list up to 65535 values in an ENUM list. If a value is inserted that is not in the list, a blank value will be inserted. **The values are sorted in the order**you enter them|
    |`SET(val1,val2,val3,...)`|A string object that can have 0 or more values, chosen from a list of possible values. You can list up to 64 values in a SET list|

    + Numeric Data Types
  
    |Data Type|Description|
    |:---:|:---:|
    |`BOOL`|Zero is considered as false, nonzero values are considered as true.|
    |`INT(size)`|A medium integer. Signed range is from -2147483648 to 2147483647. Unsigned range is from 0 to 4294967295. The size parameter specifies the maximum display width (which is 255)|
    |`FLOAT(size,d)`|A floating point number. The total number of digits is specified in size. The number of digits after the decimal point is specified in the d parameter. |
    |`DOUBLE(size,d)`|A normal-size floating point number. The total number of digits is specified in size. The number of digits after the decimal point is specified in the d parameter|

    + Date and Time Data Types

    |Data Type|Description|
    |:---:|:---:|
    |`DATE`|A date. Format: YYYY-MM-DD. The supported range is from '1000-01-01' to '9999-12-31'|
    |`TIMESTAMP(fsp)`|A timestamp. TIMESTAMP values are stored as the number of seconds since the Unix epoch ('1970-01-01 00:00:00' UTC). Format: YYYY-MM-DD hh:mm:ss. The supported range is from '1970-01-01 00:00:01' UTC to '2038-01-09 03:14:07' UTC. Automatic initialization and updating to the current date and time can be specified using DEFAULT CURRENT_TIMESTAMP and ON UPDATE CURRENT_TIMESTAMP in the column definition|

+ **Use Another table to create Table**

A copy of an existing table can also be created using `CREATE TABLE`.

```SQL
CREATE TABLE new_table_name AS
    SELECT column1, column2,...
    FROM existing_table_name
    WHERE ....;
```

The following SQL creates a new table called "TestTable" (which is a copy of the "Customers" table): 

```SQL
CREATE TABLE testtable AS
SELECT customername,contactname
FROM customers;
```

## DROP TABLE

+ The following SQL statement drops the existing table "Shippers":

```SQL
DROP TABLE Shippers
```

+ The `TRUNCATE TABLE` statement is used to delete the data inside a table, but not the table itself.

```SQL
TRUNCATE TABLE table_name;
```

## ALTER TABLE

The `ALTER TABLE` statement is used to add, delete, or modify columns in an existing table.

+ To add a column in a table:

```SQL
ALTER TABLE table_name
ADD column_name datatype;
```

+ To drop a column in a table:

```SQL
ALTER TABLE table_name
DROP COLUMN column_name;
```

+ TO rename a column in a table

```SQL
ALTER TABLE table_name
RENAME COLUMN old_name to new_name;
```

+ To change the data type of a column in a table:

```SQL
# SQL server/MS Acess
ALTER TABLE table_name
ALTER COLUMN column_name datatype;

# MySQL
ALTER TABLE table_name
MODIFY COLUMN column_name datatype;
```
