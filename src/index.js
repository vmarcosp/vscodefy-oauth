import './scss/index.scss';
import 'toastr/toastr.scss';
import toastr from 'toastr/toastr.js';
import ClipboardJS from 'clipboard';

window.onload = function () {
    const code = window.location.href.split('?code=')[1];
    if(code){
        // Todo trigger action for call vscode
        const codeDocument = document.getElementById('spotify-code');
        codeDocument.textContent = code;
        const clipboard = new ClipboardJS('.clipboard');
        clipboard.on('success',(e) => {
            e.clearSelection();
            toastr.success('OAuth code copied!','Success',{positionClass:'toast-bottom-right'})
        });
    }
    const spotifyButton = document.getElementById('spotifyButton')
    spotifyButton.addEventListener('click', () => {
        window.location.replace(getSpotifyUrl());
    });
}

function getSpotifyUrl () {
    const redirectUrl = window.location.origin;
    const CLIENT_ID = 'afdf5f70fca34efcae1f224b68728aa2';
    const scope = [
      'user-modify-playback-state',
      'user-read-playback-state',
      'user-read-private',
      'user-read-email',
      'user-read-currently-playing',
      'streaming'
    ];

    const baseURL = 'https://accounts.spotify.com/en/authorize';
    const url = `${baseURL}?client_id=${CLIENT_ID}&response_type=code&redirect_uri=${redirectUrl}`;
    return `${url}&scope=${encodeURIComponent(scope.join(','))}`;
}
