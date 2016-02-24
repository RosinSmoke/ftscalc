@echo off
del /Q /F output\data_1_lines.txt output\data_2_points.txt output\data_3_result.txt
@points.exe 1
@points.exe 2
@points.exe 4
gnuplot\bin\gnuplot.exe "gnuplot_script.txt" -persist