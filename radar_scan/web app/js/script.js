var API_KEY = "2825f857-7633-41db-a71c-2b83bdd26e8d";
var DEVICE_ID = "BOLT15316359";
var delay = 70000;

    // Function to handle button click event
    function handleButtonClick() {
  $('#btn-request').prop('disabled', true);
  $('#btn-request').html('Scanning in Progress...');
  $.get('https://cloud.boltiot.com/remote/' + API_KEY+ '/serialWrite?data=send_buff&deviceName=' + DEVICE_ID, function() {
    setTimeout(function() {
        
      // Fetch response from remote server
      $.get('https://cloud.boltiot.com/remote/' +API_KEY + '/serialRead?deviceName=' + DEVICE_ID, function(response) {
        // Extract value from response
        console.log(response);
        var value = response.value;
        // Split value string into an array of numbers
        var numbers = value.split(' ').map(Number);

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
      });
    }, 10000);
  });
}

// Add event listener for button click
$('#btn-request').click(handleButtonClick);