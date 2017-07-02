import java.io.IOException;
import java.util.Iterator;
import java.util.StringTokenizer;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class AverScore
{
    public static class ScoreMap extends
        Mapper<LongWritable, Text, Text, IntWritable>
    {
        public void map(LongWritable key, Text value, Context context)
            throws IOException, InterruptedException
        {
            String fullText = value.toString();
            StringTokenizer tokenizerText = new StringTokenizer(fullText, "\n");

            while (tokenizerText.hasMoreElements())
            {
                StringTokenizer tokenizerLine = new StringTokenizer(tokenizerText.nextToken());
                String stuName = tokenizerLine.nextToken();
                String stuScore = tokenizerLine.nextToken();
                Text textStuName = new Text(stuName);
                int scoreInt = Integer.parseInt(stuScore);
                context.write(textStuName, new IntWritable(scoreInt));
            }
        }
    }

    public static class AverScoreReducer extends
        Reducer<Text , IntWritable, Text, IntWritable>
    {
        public void reduce(Text key, Iterable<IntWritable> values,
                           Context context) throws IOException, InterruptedException
        {
            int sum = 0;
            int count = 0;
            Iterator<IntWritable> iterator = values.iterator();
            while(iterator.hasNext())
            {
                sum += iterator.next().get();
                ++count;
            }

            int average = (int) sum / count;
            context.write(key, new IntWritable(average));
        }
    }

    public static void main(String[] args) throws Exception
    {
        Configuration conf = new Configuration();
        // "localhost:9000" 需要根据实际情况设置一下
        conf.set("mapred.job.tracker", "localhost:54320");
          // 一个hdfs文件系统中的 输入目录 及 输出目录
        String[] ioArgs = new String[] { "input/score", "output" };
        String[] otherArgs = new GenericOptionsParser(conf, ioArgs).getRemainingArgs();
        if (otherArgs.length != 2) {
            System.err.println("Usage: Score Average <in> <out>");
            System.exit(2);
        }

        Job job = new Job(conf, "Score Average");
        job.setJarByClass(AverScore.class);
        // 设置Map、Combine和Reduce处理类
        job.setMapperClass(ScoreMap.class);
        job.setCombinerClass(AverScoreReducer.class);
        job.setReducerClass(AverScoreReducer.class);
        // 设置输出类型
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);
        // 将输入的数据集分割成小数据块splites，提供一个RecordReder的实现
        job.setInputFormatClass(TextInputFormat.class);
        // 提供一个RecordWriter的实现，负责数据输出
        job.setOutputFormatClass(TextOutputFormat.class);
        // 设置输入和输出目录

        System.out.println(otherArgs[0]);
        System.out.println(otherArgs[1]);
        FileInputFormat.addInputPath(job, new Path(otherArgs[0]));
        FileOutputFormat.setOutputPath(job, new Path(otherArgs[1]));
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
