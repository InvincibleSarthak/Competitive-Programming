int tour(petrolPump arr[],int n)
{
   int start = 0, end = 1;
   int curr = arr[start].petrol - arr[start].distance;
   while(end != start || curr < 0){
       while(curr < 0 && start != end){
           curr -= arr[start].petrol - arr[start].distance;
           start = (start+1)%n;
           
           if(start == 0)   return -1;
       }
       curr += arr[end].petrol - arr[end].distance;
       end = (end+1)%n;
   }
   return start; 
}
