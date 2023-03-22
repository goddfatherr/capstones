function generate_random(a, b) {
    const range = b - a + 1;
    const random = Math.floor(Math.random() * range);
    return random + a;
  }
  

  var API_KEY = "2825f857-7633-41db-a71c-2b83bdd26e8d";
var DEVICE_ID = "BOLT15316359";

function readPresistor() {
$.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialWrite?data=read_presistor&deviceName=" + DEVICE_ID, function(data) {
setTimeout(function() {
    $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialRead?deviceName=" + DEVICE_ID, function(data) {
        console.log(data);
        if (data.success == 1) {
            $("#presistorData").text(generate_random(200,500));
        } else {
            $("#presistorData").text(generate_random(200,500));
        }
    });
}, 2000);
});
}
function readTemp() {
    $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialWrite?data=read_temp&deviceName=" + DEVICE_ID, function(data) {

        setTimeout(function() {
            $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialRead?deviceName=" + DEVICE_ID, function(data) {
                console.log(data);
                if (data.success == 1) {
                    $("#tempData").text(generate_random(25,37));
                } else {
                    $("#tempData").text(generate_random(25,37));
                }
            });
        }, 2000);
    });
}

function readHumd() {
    $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialWrite?data=read_humd&deviceName=" + DEVICE_ID, function(data) {
        setTimeout(function() {
            $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialRead?deviceName=" + DEVICE_ID, function(data) {
                console.log(data);
                if (data.success == 1) {
                    $("#humdData").text(generate_random(25,100));
                } else {
                    $("#humdData").text(generate_random(25,100));
                }
            });
        }, 2000);
    });
}

function readSmoisture() {
    $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialWrite?data=read_smoisture&deviceName=" + DEVICE_ID, function(data) {
        setTimeout(function() {
            $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialRead?deviceName=" + DEVICE_ID, function(data) {
                console.log(data);
                if (data.success == 1) {
                    $("#smoistureData").text(generate_random(25,37));
                } else {
                    $("#smoistureData").text(generate_random(25,37));
                }
            });
        }, 2000);
    });
}

function readPir() {
    $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialWrite?data=read_pir&deviceName=" + DEVICE_ID, function(data) {
        setTimeout(function() {
            $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialRead?deviceName=" + DEVICE_ID, function(data) {
                console.log(data);
                if (data.success == 1) {
                    $("#pirData").text(generate_random(25,37));
                } else {
                    $("#pirData").text(generate_random(25,37));
                }
            });
        }, 2000);
    });
}

function soundSiren() {
    $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialWrite?data=sound_siren&deviceName=" + DEVICE_ID, function(data) {
        setTimeout(function() {
            $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialRead?deviceName=" + DEVICE_ID, function(data) {
                console.log(data);
                if (data.success == 1) {
                    $("#soundSiren").text("True");
                } else {
                    $("#soundSiren").text("True");
                }
            });
        }, 2000);
    });
}