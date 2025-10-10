
# SQL Data Manipulation Language

## INSERT INTO

+ Insert data only in specified Columns

```SQL
INSERT INTO tabel_name (Col1,Col2,...)
VALUE (Val1,Val2,...);
```

+ Insert all columns of data

```SQL
INSERT INTO table_name
VALUE (Val1,Val2,Val3,...);
```

+ Insert Mutiple Rows

```SQL
INSERT INTO table_name (col1,col2,...)
VALUE
(val00,val01,...),
(val10,val11,...);
```

## Update

The `UPDATE` statement is to modify the existing records in the table.

```SQL
UPDATE table_name
SET col1 = val1,col2 = val2,...
WHERE condition;
```

!!! WARNING "'WHERE' clause in Update Statement"
    If you omit the WHERE clause, all records in the table will be updated!

## Delete

The `Delete` statement is to remove the existing records of a table.

```SQL
DELETE FROM table_name WHERE conditions;
```

!!! WARNING "'WHERE' clause in DELETE Statement"
    If you omit the WHERE clause, **all records in the table will be removed**!

+ Delete all records of a table:

```SQL
DELETE FROM table_name;
```

+ Delete a table **completely**:

```SQL
DELETE TABLE table_name;
```