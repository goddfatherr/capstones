var API_KEY = "2825f857-7633-41db-a71c-2b83bdd26e8d";
var DEVICE_ID = "BOLT15316359";

function readPresistor() {
$.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialWrite?data=read_presistor&deviceName=" + DEVICE_ID, function(data) {
setTimeout(function() {
    $.get("https://cloud.boltiot.com/remote/" + API_KEY + "/serialRead?deviceName=" + DEVICE_ID, function(data) {
        console.log(data);
        if (data.success == 1) {
            $("#presistorData").text(data.value);
        } else {
            $("#presistorData").text("Error reading sensor data");
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
                    $("#tempData").text(data.value);
                } else {
                    $("#tempData").text("Error reading sensor data");
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
                    $("#humdData").text(data.value);
                } else {
                    $("#humdData").text("Error reading sensor data");
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
                    $("#smoistureData").text(data.value);
                } else {
                    $("#smoistureData").text("Error reading sensor data");
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
                    $("#pirData").text(data.value);
                } else {
                    $("#pirData").text("Error reading sensor data");
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
                    $("#soundSiren").text(data.value);
                } else {
                    $("#soundSiren").text("Error reading sensor data");
                }
            });
        }, 2000);
    });
}