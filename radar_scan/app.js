<!DOCTYPE html>
<html>
<head>
  <title>Bolt IoT Button</title>
  <!-- Add Bootstrap CSS -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <!-- Add custom CSS for button and plot styling -->
  <style>
    /* Style for the button */
    .btn-bolt {
      background-color: #007bff;
      color: #fff;
    }

    /* Style for the plot container */
    #plot-container {
      width: 100%;
      height: 400px;
    }
  </style>
</head>
<body>
  <div class="container mt-5">
    <h1 class="text-center mb-4">Bolt IoT Button</h1>
    <button id="btn-request" class="btn btn-bolt btn-block">Press to Request Data</button>
    <div id="plot-container" class="mt-3"></div>
  </div>

  <!-- Add Bootstrap and Plotly JavaScript libraries -->
  <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
  <script src="https://cdn.plot.ly/plotly-latest.min.js"></script>

  <script>
    // Function to handle button click event
    function handleButtonClick() {
      // Disable the button
      $('#btn-request').prop('disabled', true);
      // Change button text to show request in progress
      $('#btn-request').html('Request in Progress...');
      // Make API request
      $.get('https://cloud.boltiot.com/remote/{API_KEY}/serialWrite?data=getAnalogData&deviceName={DEVICE_ID}', function(response) {
        // Extract values from response
        var valueString = response.value;
        var values = valueString.split(' ');
        // Convert values to numbers
        var buffer = values.map(Number);
        // Create plot
        var plotData = [{
          x: buffer,
          type: 'line'
        }];
        var plotLayout = {
          title: 'Analog Data',
          xaxis: {
            title: 'Index'
          },
          yaxis: {
            title: 'Value'
          }
        };
        Plotly.newPlot('plot-container', plotData, plotLayout);
        // Enable the button after 10 seconds
        setTimeout(function() {
          $('#btn-request').prop('disabled', false);
          $('#btn-request').html('Request Complete');
        }, 10000);
      });
    }

    // Add event listener for button click
    $('#btn-request').click(handleButtonClick);
  </script>
</body>
</html>
