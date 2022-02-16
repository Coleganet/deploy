docker build --pull  -t app --build-arg ssh_prv_key="$(cat /root/.ssh/id_rsa)" --build-arg ssh_pub_key="$(cat /root/.ssh/id_rsa.pub)" --squash .
