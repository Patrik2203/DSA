class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.length;
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
        
        for(int i = 0; i < n; i++){
            double currPR = (double)(classes[i][0] / (double)classes[i][1]);
            double delta = (double)((classes[i][0] + 1) / (double)(classes[i][1] + 1)) - currPR;
            maxHeap.add(new double[]{delta, i});
        }
        // for(double z: PR){System.out.print(z + " ");}

        while(extraStudents > 0){ 

            double[] curr = maxHeap.poll();

            double d = curr[0]; //delta
            int index = (int)curr[1];

            // PR[index] += d;
            classes[index][0] += 1;
            classes[index][1] += 1;

            double currPR = (double)(classes[index][0] / (double)classes[index][1]);

            double newPR = (double)((classes[index][0] + 1) / (double)(classes[index][1] + 1));

            double deltaDifferene = (newPR - currPR);
            maxHeap.add(new double[]{deltaDifferene, index});

            extraStudents--;
        }
        // System.out.println();
        // for(double z: PR){System.out.print(z + " ");}

        double sum = 0.0;
        for (int[] cls : classes) {
            sum += (double) cls[0] / cls[1];
        }
        return sum / (double)n;
    }
}
