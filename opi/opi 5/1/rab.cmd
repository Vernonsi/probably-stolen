FOR %%v IN (MIN,MAX,SUM,AVG) DO (SET FUNCTION=%%v
series.exe < a.txt >> b.txt)
