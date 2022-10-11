class BinaryGap {
    public static void main (String args[])
    {
        BinaryGap binaryGap = new BinaryGap();
        int n = 261;
        System.out.println("Max count : "+binaryGap.binaryValue(n));
    }
    
    public int binaryValue(int N) {
        String binaryValue = Integer.toBinaryString(N);
        System.out.println("binaryValue : "+binaryValue);
        int maxZeroCount = 0;
        int zeroCount = 0;
        for (int i = 0, n = binaryValue.length(); i < n; i++) {
            if(binaryValue.charAt(i) == '0') {
                ++zeroCount;
            } else {
                if(zeroCount > maxZeroCount) {
                    maxZeroCount = zeroCount;
                }
                zeroCount = 0;
            }
        }
        return maxZeroCount;
    }
}