SELECT * FROM Employeesview WHERE Department = 'Marketing';

SELECT Department, COUNT(Name) FROM Employeesview GROUP BY Department;

SELECT Employees.Name From Employees JOIN POSITIONS ON Employees.PositionID = Positions.ID 
WHERE Positions.Name = 'Accountant' AND (Age >= 30 AND Age <= 45);