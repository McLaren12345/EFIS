
//卡尔曼滤波的过程噪声与测量噪声都是先验知识，必须人为给定，通常通过观察得出。
//也存在自适应噪声的卡尔曼滤波算法
double KalmanFilter(const double ResrcData,double ProcessNiose_Q,double MeasureNoise_R)
{
        static double x_last;
        static double p_last;
        double R = MeasureNoise_R;
        double Q = ProcessNiose_Q;
        double x_mid = x_last;
        double x_now;
        double p_mid ;
        double p_now;
        double kg;   

        x_mid=x_last; //x_last=x(k-1|k-1),x_mid=x(k|k-1)
        p_mid=p_last+Q; //p_mid=p(k|k-1),p_last=p(k-1|k-1),Q=噪声
        kg=p_mid/(p_mid+R); //kg为kalman filter，R为噪声
        x_now=x_mid+kg*(ResrcData-x_mid);//估计出的最优值

        p_now=(1-kg)*p_mid;//最优值对应的covariance      

        p_last = p_now; //更新covariance值
        x_last = x_now; //更新系统状态值

        return x_now;               
}
