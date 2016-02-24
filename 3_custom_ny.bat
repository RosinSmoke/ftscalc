@echo off
del /Q /F output\data_1_lines.txt output\data_2_points.txt output\data_3_result.txt
@points.exe 3
REM path\to\gnuplot\bin\gnuplot.exe "gnuplot_script.txt" -persist
gnuplot "gnuplot_script.txt" -persist