    // Function to handle button click event

      function handleButtonClick() {
        $('#btn-request').prop('disabled', true);
        $('#btn-request').html('Scanning in Progress...');
      
        // Delay the radar scan by 10 seconds
        setTimeout(function() {
          //generate random numbers to simulate radar scan
          //range -> 10 - 90
          var numbers = [];
          for (var i = 0; i < 180; i++) {
            numbers.push(Math.floor(Math.random() * 81) + 10);
          }
      
           // Create a Plotly trace for the filled area plot
        var trace = {
            x: numbers.map(function(_, i) { return i; }),
            y: numbers,
            type: 'scatter',
            mode: 'lines',
            fill: 'tozeroy',
            line: { color: 'rgba(41, 128, 185, 1)', width: 2 },
            fillcolor: 'rgba(41, 128, 185, 0.4)'
          };
  
          var data = [trace];
          // Create a Plotly layout with axis labels and title
          var layout = {
            xaxis: {
              title: 'Angle(&deg;)',
              showline: true,
              linewidth: 2,
              linecolor: 'rgba(0, 0, 0, 0.6)'
            },
            yaxis: {
              title: 'Distance(cm)',
              showline: true,
              linewidth: 2,
              linecolor: 'rgba(0, 0, 0, 0.6)'
            },
            title: {
              text: 'Environment Outline',
              font: { size: 24 },
              x: 0.5
            },
            margin: { t: 80 },
            paper_bgcolor: 'rgba(255, 255, 255, 0.8)',
            plot_bgcolor: 'rgba(255, 255, 255, 0.8)',
          };
  
          Plotly.newPlot('plot-container', data, layout);

           // Enable the button after request is complete
         $('#btn-request').prop('disabled', false);
         $('#btn-request').html('Scan Complete');
        }, 10000); // 10 seconds delay

        
      
      }
           
// Add event listener for button click
$('#btn-request').click(handleButtonClick);