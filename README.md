cnips
=====

获取中国的 IP 地址范围

用法
===

```
gcc cnips.c -O2 -o cnips

wget http://ftp.apnic.net/apnic/stats/apnic/delegated-apnic-latest
cat delegated-apnic-latest | ./cnips

```

配合 iproute2 来设置路由表
===

```
for net in `cat delegated-apnic-latest | ./cnips`
do
  ip route add $net via <your_gateway> table <your_rule_table>
done
```
