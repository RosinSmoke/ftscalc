# ftscalc
Calculator of Fermat-Torricelli-Steiner point coordinates for a set of input points

###Features:
 - **Optimized search**: instead of slicing search area into a big grid (classic attempt) and searching for a cell with minimum value of FTS function, this code continues slicing the "minimum" cell again until you have the desired precision. So instead of **O(N\*M)** operations with too big *N* and *M* grid sizes you can use small *n* and *m* values (currently 3\*3 grid) and get the **O(n\*m\*steps)** operations. 
 - **Set the precision** instead of calculating it from the affordable grid size. Each step gives you observational error of _(n^(-j))*(axis\_max-axis\_min)_ (where j is number of step), so the slicing can be stopped when the "minimum" cell is smaller than allowed observational error
 - Calculations in **different [p-norms](https://en.wikipedia.org/wiki/Lp_space#The_p-norm_in_finite_dimensions)** : 
* L\_2 metric ([Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance))
* L\_1 metric ([Taxicab distance](https://en.wikipedia.org/wiki/Manhattan_distance)) 
* L\_infinity ([Chessboard distance](https://en.wikipedia.org/wiki/Chebyshev_distance))
 - Custom affin coordinates system for L\_1


 The program was built using TDM-GCC 4.9.2 with Dev-C++ 5.11 on MS Windows, I didn't test it on unix-based systems or in Cygwin, but there should not be any major issues building it elswhere.

###Usage

Put _input.txt_ data file into the same folder with _points.exe_ and _"output"_ folder. By default calculations are done in Euclidean distance, but you may set the metric adding 1, 2, 3 or 4 as launch key in console (Euclidean, taxicab, taxicab in custom coordinate system and chessboard distance accordingly).

Input points' coordinates should be formatted like

```
x1 y1
x2 y2
... ... 
```


Afrer running _points.exe_ you can find the result in _output/data_3_result.txt_ file.

###Graphs
If you have gnuplot installed, there are 4 batch scripts included so you could see what the result looks like in "reality". Demo input and gnuplot script are included in root and "output" folders accordingly.

######Euclidean
![](https://raw.githubusercontent.com/RosinSmoke/content/master/euclidis.png)

######Taxicab
(Actually, ane point from green area is a FTS point)
![](https://raw.githubusercontent.com/RosinSmoke/content/master/taxicab.png)

######Taxicab with custom affin coordinate system
(for example, rotated 45 degrees to the left)
![](https://raw.githubusercontent.com/RosinSmoke/content/master/taxicab_custom.png)

######Chessboard
![](https://raw.githubusercontent.com/RosinSmoke/content/master/chessboard.png)