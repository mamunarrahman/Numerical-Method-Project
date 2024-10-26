void Jacobi_Iterative_Method(vector<vector<double>> &coefficient,vector<double> &rhs,vector<double>&initial)
{
    int n=coefficient.size();
    vector<double> x(n,0.0);
    for(int i=0;i<max_loop;i++)
    {
        for(int j=0;j<n;j++)
        {
            double approx=0.0;
            for(int k=0;k<n;k++)
            {
                if(j!=k)
                {
                    approx=approx+coefficient[j][k]*initial[k];
                }   
            }
            x[j]=(rhs[j]-approx)/coefficient[j][j];
        }
        double max_error=0.0;
        for(int k=0;k<n;k++)
        {
            max_error=max(max_error,fabs(x[k]-initial[k]));

        }
        if(max_error<max_tolerance)
        {
            break;
        }
        initial=x;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"x"<<i+1<<"= "<<initial[i]<<endl;
    }
}
