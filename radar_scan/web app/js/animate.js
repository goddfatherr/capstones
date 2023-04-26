var API_KEY = "2825f857-7633-41db-a71c-2b83bdd26e8d";
var DEVICE_ID = "BOLT15316359";
var delay = 70000;

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
            x: [],
            y: [],
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
              title: 'Index',
              showline: true,
              linewidth: 2,
              linecolor: 'rgba(0, 0, 0, 0.6)'
            },
            yaxis: {
              title: 'Value',
              showline: true,
              linewidth: 2,
              linecolor: 'rgba(0, 0, 0, 0.6)'
            },
            title: {
              text: 'Plot of Values',
              font: { size: 24 },
              x: 0.5
            },
            margin: { t: 80 },
            paper_bgcolor: 'rgba(255, 255, 255, 0.8)',
            plot_bgcolor: 'rgba(255, 255, 255, 0.8)',
            updatemenus: [{
              type: 'buttons',
              showactive: false,
              buttons: [{
                label: 'Play',
                method: 'animate.play'
              }, {
                label: 'Pause',
                method: 'animate.pause'
              }, {
                label: 'Stop',
                method: 'animate.stop'
              }]
            }]
          };
  
          // Create animation frames
          var frames = [];
          for (var i = 0; i < numbers.length; i++) {
            frames.push({
              data: [{
                x: numbers.slice(0, i+1).map(function(_, j) { return j; }),
                y: numbers.slice(0, i+1),
              }],
              traces: [0]
            });
          }
  
          // Add frames to layout
          layout.updatemenus[0].buttons[0].args = [null, {
            fromcurrent: true,
            frame: {redraw: false, duration: 1000},
            transition: {duration: 500, easing: 'linear'}
          }];
  
                  // Create animation settings
        var animationSettings = {
            frames: frames,
            animation: {
              fromcurrent: true,
              frame: {redraw: false, duration: 1000},
              transition: {duration: 500, easing: 'linear'}
            }
          };
  
          // Add animation settings to layout
          layout.updatemenus[0].buttons[0].args[1].frame = animationSettings.animation;
  
          // Create the Plotly plot
          Plotly.newPlot('chart', data, layout).then(function() {
            Plotly.addFrames('chart', animationSettings.frames);
          });
  
          $('#btn-request').html('Start Scanning');
          $('#btn-request').prop('disabled', false);
        }).fail(function() {
          console.error('Failed to fetch response');
          $('#btn-request').html('Start Scanning');
          $('#btn-request').prop('disabled', false);
        });
      }, 10000);
    }).fail(function() {
      console.error('Failed to send request');
      $('#btn-request').html('Start Scanning');
      $('#btn-request').prop('disabled', false);
    });
  }
    
 // Add event listener for button click
$('#btn-request').click(handleButtonClick); 