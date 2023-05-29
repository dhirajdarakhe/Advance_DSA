hadoop
which hadoop
start-all.sh 
cd dsbda
hdfs dfs -mkdir /word
hadoop fs -put input.txt /word
$HADOOP_HOME
cd $HADOOP_HOME/share/hadoop/mapreduce
ls 
hadoop jar map-reduce-example-3.3.3.jar wordcount /word /output
hadoop fs -ls /output
hadoop fs -cat output/part-r-00000spark-shell
......

spark-shell
var a = sc.textFile("file.txt")
var b = a.flatMap(_.split(" "))
var c = b.map(word => (word, 1))
var d = c.reduceByKey(_+_)
d.foreach(println)
