/*
 * torture_key.c - torture library for testing libssh
 *
 * This file is part of the SSH Library
 *
 * Copyright (c) 2008-2009 by Andreas Schneider <asn@cryptomilk.org>
 *
 * The SSH Library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * The SSH Library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the SSH Library; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */

#include "config.h"

#include <libssh/priv.h>

#include "torture_key.h"

/****************************************************************************
 * DSA KEYS
 ****************************************************************************/
static const char torture_rsa_private_testkey[] =
        "-----BEGIN RSA PRIVATE KEY-----\n"
        "MIIEowIBAAKCAQEArAOREUWlBXJAKZ5hABYyxnRayDZP1bJeLbPVK+npxemrhHyZ\n"
        "gjdbY3ADot+JRyWjvll2w2GI+3blt0j+x/ZWwjMKu/QYcycYp5HL01goxOxuusZb\n"
        "i+KiHRGB6z0EMdXM7U82U7lA/j//HyZppyDjUDniWabXQJge8ksGXGTiFeAJ/687\n"
        "uV+JJcjGPxAGFQxzyjitf/FrL9S0WGKZbyqeGDzyeBZ1NLIuaiOORyLGSW4duHLD\n"
        "N78EmsJnwqg2gJQmRSaD4BNZMjtbfiFcSL9Uw4XQFTsWugUDEY1AU4c5g11nhzHz\n"
        "Bi9qMOt5DzrZQpD4j0gA2LOHpHhoOdg1ZuHrGQIDAQABAoIBAFJTaqy/jllq8vZ4\n"
        "TKiD900wBvrns5HtSlHJTe80hqQoT+Sa1cWSxPR0eekL32Hjy9igbMzZ83uWzh7I\n"
        "mtgNODy9vRdznfgO8CfTCaBfAzQsjFpr8QikMT6EUI/LpiRL1UaGsNOlSEvnSS0Z\n"
        "b1uDzAdrjL+nsEHEDJud+K9jwSkCRifVMy7fLfaum+YKpdeEz7K2Mgm5pJ/Vg+9s\n"
        "vI2V1q7HAOI4eUVTgJNHXy5ediRJlajQHf/lNUzHKqn7iH+JRl01gt62X8roG62b\n"
        "TbFylbheqMm9awuSF2ucOcx+guuwhkPir8BEMb08j3hiK+TfwPdY0F6QH4OhiKK7\n"
        "MTqTVgECgYEA0vmmu5GOBtwRmq6gVNCHhdLDQWaxAZqQRmRbzxVhFpbv0GjbQEF7\n"
        "tttq3fjDrzDf6CE9RtZWw2BUSXVq+IXB/bXb1kgWU2xWywm+OFDk9OXQs8ui+MY7\n"
        "FiP3yuq3YJob2g5CCsVQWl2CHvWGmTLhE1ODll39t7Y1uwdcDobJN+ECgYEA0LlR\n"
        "hfMjydWmwqooU9TDjXNBmwufyYlNFTH351amYgFUDpNf35SMCP4hDosUw/zCTDpc\n"
        "+1w04BJJfkH1SNvXSOilpdaYRTYuryDvGmWC66K2KX1nLErhlhs17CwzV997nYgD\n"
        "H3OOU4HfqIKmdGbjvWlkmY+mLHyG10bbpOTbujkCgYAc68xHejSWDCT9p2KjPdLW\n"
        "LYZGuOUa6y1L+QX85Vlh118Ymsczj8Z90qZbt3Zb1b9b+vKDe255agMj7syzNOLa\n"
        "/MseHNOyq+9Z9gP1hGFekQKDIy88GzCOYG/fiT2KKJYY1kuHXnUdbiQgSlghODBS\n"
        "jehD/K6DOJ80/FVKSH/dAQKBgQDJ+apTzpZhJ2f5k6L2jDq3VEK2ACedZEm9Kt9T\n"
        "c1wKFnL6r83kkuB3i0L9ycRMavixvwBfFDjuY4POs5Dh8ip/mPFCa0hqISZHvbzi\n"
        "dDyePJO9zmXaTJPDJ42kfpkofVAnfohXFQEy+cguTk848J+MmMIKfyE0h0QMabr9\n"
        "86BUsQKBgEVgoi4RXwmtGovtMew01ORPV9MOX3v+VnsCgD4/56URKOAngiS70xEP\n"
        "ONwNbTCWuuv43HGzJoVFiAMGnQP1BAJ7gkHkjSegOGKkiw12EPUWhFcMg+GkgPhc\n"
        "pOqNt/VMBPjJ/ysHJqmLfQK9A35JV6Cmdphe+OIl28bcKhAOz8Dw\n"
        "-----END RSA PRIVATE KEY-----\n";

static const char torture_rsa_private_testkey_passphrase[] =
        "-----BEGIN RSA PRIVATE KEY-----\n"
        "Proc-Type: 4,ENCRYPTED\n"
        "DEK-Info: AES-128-CBC,5375534F40903DD66B3851A0DA03F6FA\n"
        "\n"
        "m5YYTNOMd1xCKfifwCX4R1iLJoAc4cn1aFiL7f2kBbfE2jF1LTQBJV1h1CqYZfAB\n"
        "WtM/7FkQPnKXqsMndP+v+1Xc+PYigE3AezJj/0g7xn/zIBwGjkLAp435AdL5i6Fg\n"
        "OhOL8LyolRrcGn17jE4S4iGbzw8PVyfzNzdj0Emwql5F6M7pgLbInRNKM/TF4z2h\n"
        "b6Pi9Bw43dwaJ7wiiy/vo/v4MyXsJBoeKbc4VCmxiYFvAYCvVFlDkyIw/QnR3MKQ\n"
        "g/Zsk7Pw3aOioxk6LJpZ5x0tO23nXDG1aOZHWykI0BpJV+LIpD2oSYOHJyVO83XT\n"
        "RQUMSTXc2K2+ejs0XQoLt/GxDDHe+8W8fWQK3C7Lyvl9oKjmb5sTWi3mdSv0C+zR\n"
        "n5KSVbUKNXrjix7qPKkv5rWqb84CKVnCMb7tWaPLR19nQqKVYBIs6v0OTTvS6Le7\n"
        "lz4lxBkcUy6vi0tWH9MvLuT+ugdHLJZ4UXBthCgV58pM1o+L+WMIl+SZXckiCAO3\n"
        "7ercA57695IA6iHskmr3eazJsYFEVFdR/cm+IDy2FPkKmJMjXeIWuh3yASBk7LBR\n"
        "EQq3CC7AioO+Vj8m/fEIiNZJSQ6p0NmgnPoO3rTYT/IobmE99/Ht6oNLmFX4Pr7e\n"
        "F4CGWKzwxWpCnw2vVolCFByASmZycbJvrIonZBKY1toU28lRm4tCM6eCNISVLMeE\n"
        "VtQ+1PH9/2KZspZl+SX/kjV3egggy0TFKRU8EcYPJFC3Vpy+shEai35KBVo44Z18\n"
        "apza7exm3igNEqOqe07hLs3Bjhvk1oS+WhMbAG9ARTOKuyBOJh/ZV9tFMNZ6v+q5\n"
        "TofgNcIhNYNascymU1io18xTW9c3RRcmRKqIWnj4EH8o7Aojv/l+zvdV7/GVlR4W\n"
        "pR9cuJEiyiEjS46axoc6dSOtdnvag+BpFQb+lGY97F9nNGyBdtLD5ASVh5OVG4fu\n"
        "Pf0O7Bdj1kIuBhV8axE/slf6UHANiodeqkR9B24+0Cy+miPiHazzUkbdSJ4r03g5\n"
        "J1Y5S8qbl9++sqhQMLMUkeK4pDWh1aocA9bDA2RcBNuXGiZeRFUiqxcBS+iO418n\n"
        "DFyWz4UfI/m1IRSjoo/PEpgu5GmosUzs3Dl4nAcf/REBEX6M/kKKxHTLjE8DxDsz\n"
        "fn/vfsXV3s0tbN7YyJdP8aU+ApZntw1OF2TS2qS8CPWHTcCGGTab5WEGC3xFXKp0\n"
        "uyonCxV7vNLOiIiHdQX+1bLu7ps7GBH92xGkPg7FrNNcMc07soP7jjjB578n9Gpl\n"
        "cIDBdgovTRFHiWu3yRspVt0zPfMJB/hqn+IAp98wfvjl8OZM1ZZkejnwXnQil5ZU\n"
        "wjEBEtx+nX56vdxipzKoHh5yDXmPbNajBYkg3rXJrLFh3Tsf0CzHcLdHNz/qJ9LO\n"
        "wH16grjR1Q0CzCW3FAv0Q0euqkXac+TfuIg3HiTPrBPnJQW1uivrx1F5tpO/uboG\n"
        "h28LwqJLYh+1T0V//uiy3SMATpYKvzg2byGct9VUib8QVop8LvVF/n42RaxtTCfw\n"
        "JSvUyxoaZUjQkT7iF94HsF+FVVJdI55UjgnMiZ0d5vKffWyTHYcYHkFYaSloAMWN\n"
        "-----END RSA PRIVATE KEY-----\n";

static const char torture_rsa_public_testkey[] =
        "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCsA5ERRaUFckApnmEAFjLGdFrIN"
        "k/Vsl4ts9Ur6enF6auEfJmCN1tjcAOi34lHJaO+WXbDYYj7duW3SP7H9lbCMwq79B"
        "hzJxinkcvTWCjE7G66xluL4qIdEYHrPQQx1cztTzZTuUD+P/8fJmmnIONQOeJZptd"
        "AmB7ySwZcZOIV4An/rzu5X4klyMY/EAYVDHPKOK1/8Wsv1LRYYplvKp4YPPJ4FnU0"
        "si5qI45HIsZJbh24csM3vwSawmfCqDaAlCZFJoPgE1kyO1t+IVxIv1TDhdAVOxa6B"
        "QMRjUBThzmDXWeHMfMGL2ow63kPOtlCkPiPSADYs4ekeGg52DVm4esZ "
        "aris@aris-air\n";

static const char torture_rsa_testkey_cert[] =
        "ssh-rsa-cert-v01@openssh.com AAAAHHNzaC1yc2EtY2VydC12MDFAb3BlbnNz"
        "aC5jb20AAAAgL77S/SgY969FbEtNBsbLvvtGFgnEHaPb+V7ajwuf+R0AAAADAQABA"
        "AABAQCsA5ERRaUFckApnmEAFjLGdFrINk/Vsl4ts9Ur6enF6auEfJmCN1tjcAOi34"
        "lHJaO+WXbDYYj7duW3SP7H9lbCMwq79BhzJxinkcvTWCjE7G66xluL4qIdEYHrPQQ"
        "x1cztTzZTuUD+P/8fJmmnIONQOeJZptdAmB7ySwZcZOIV4An/rzu5X4klyMY/EAYV"
        "DHPKOK1/8Wsv1LRYYplvKp4YPPJ4FnU0si5qI45HIsZJbh24csM3vwSawmfCqDaAl"
        "CZFJoPgE1kyO1t+IVxIv1TDhdAVOxa6BQMRjUBThzmDXWeHMfMGL2ow63kPOtlCkP"
        "iPSADYs4ekeGg52DVm4esZAAAAAAAAAAAAAAABAAAADmxpYnNzaF90b3J0dXJlAAA"
        "AAAAAAAAAAAAA//////////8AAAAAAAAAggAAABVwZXJtaXQtWDExLWZvcndhcmRp"
        "bmcAAAAAAAAAF3Blcm1pdC1hZ2VudC1mb3J3YXJkaW5nAAAAAAAAABZwZXJtaXQtc"
        "G9ydC1mb3J3YXJkaW5nAAAAAAAAAApwZXJtaXQtcHR5AAAAAAAAAA5wZXJtaXQtdX"
        "Nlci1yYwAAAAAAAAAAAAABFwAAAAdzc2gtcnNhAAAAAwEAAQAAAQEAoowcv2Gn8tO"
        "eDyw/lgdMpoBsLtHTTdVVOOo5HwMFvj/lFkbZlb6J2n9GIE64HNPE45vSnIdJZwz4"
        "UYfTvtnNKNHp1MgMrjK1Z6EjyZsGqDZ+BhmvcKA6IckkhBJnDV7U9dMrovAWha61Z"
        "9GpDqB1naRfbwqJQwSRHF1p71Cnf0fZKxOhAVx0ophmYGz3x3qq4PeOZv3Yl0AHTV"
        "dRmqmeELDUxeuXN2bgSyb881zEgdaKHH5oWySykP4uwjn6T7ETuL2MsDdG3HZHDhn"
        "LzLmfzOZ/cNadMCrgauMluQKc5dYF2TSeDaUxwun/NPMQBVZdETHLAMBgkGmhRUku"
        "flVDIQAAAQ8AAAAHc3NoLXJzYQAAAQADSp4b/Zta8zs6v47iwmxV2Gbucvt1kDrvT"
        "vKAKSbGN0+zoMyXiNfMHM/OvZObDS/WWGs4GMRqbJavwO3ja/dQY17oJss23lZ+Rc"
        "Lw4Rqsi3/ZEPCnX6ficiRS/yRN/LAkoXvx9vBx9QHfxlzF6JXq07wTt21zxW0tntd"
        "8dL+JI9ZZ9YylnxF3gHqfRFe2ahJpiywmxm0yOZgDmimOhep59i6BH5zHiPALvpge"
        "Mbk075oA5K9XKsHTflCcsQRQH+pXqaNQGL37z2CFz9oezxQYvIqqKF0w/eeRIARoA"
        "neB6OdgTpKFsmgPZVtqrvhjw+b5T8a4W4iWSl+6wg6gowAm "
        "rsa_privkey.pub\n";

/****************************************************************************
 * DSA KEYS
 ****************************************************************************/

static const char torture_dsa_private_testkey[] =
        "-----BEGIN DSA PRIVATE KEY-----\n"
        "MIIBuwIBAAKBgQCUyvVPEkn3UnZDjzCzSzSHpTltzr0Ec+1mz/JACjHMBJ9C/W/P\n"
        "wvH3yjkfoFhhREvoY7IPnwAu5bcxw8TkISq7YROQ409PqwwPvy0N3GUp/+kKS268\n"
        "BIJ+VKN513XRf7eL1e4aHUJ+al9x1JxTmc6T0GBq1lyu+CTUUyh25aNDFwIVAK84\n"
        "j20GmU+zewjQwsIXuVb6C/PHAoGAXhuIVsJxUQJ5nWQRLf7o3XEGQ+EcVmHOzMB1\n"
        "xCsHjYnpEhhco+r/HDZSD31kzDeAZUycz31WqGL8yXr+OZRLqEsGC7dwEAzPiXDu\n"
        "l0zHcl0yiKPrRrLgNJHeKcT6JflBngK7jQRIVUg3F3104fbVa2rwaniLl4GSBZPX\n"
        "MpUdng8CgYB4roDQBfgf8AoSAJAb7y8OVvxt5cT7iqaRMQX2XgtW09Nu9RbUIVS7\n"
        "n2mw3iqZG0xnG3iv1oL9gwNXMLlf+gLmsqU3788jaEZ9IhZ8VdgHAoHm6UWM7b2u\n"
        "ADmhirI6dRZUVO+/iMGUvDxa66OI4hDV055pbwQhtxupUatThyDzIgIVAI1Hd8/i\n"
        "Pzsg7bTzoNvjQL+Noyiy\n"
        "-----END DSA PRIVATE KEY-----\n";

static const char torture_dsa_private_testkey_passphrase[] =
        "-----BEGIN DSA PRIVATE KEY-----\n"
        "Proc-Type: 4,ENCRYPTED\n"
        "DEK-Info: AES-128-CBC,266023B64B1B814BCD0D0E477257F06D\n"
        "\n"
        "QJQErZrvYsfeMNMnU+6yVHH5Zze/zUFdPip7Bon4T1wCGlVasn4x/GQcMm1+mgmb\n"
        "PCK/qJ5qw9nCepLYJq2xh8gohbwF/XKxeaNGcRA2+ancTooDUjeRTlk1WRtS1+bq\n"
        "LBkwhxLXW26lIuQUHzfi93rRqQI2LC4McngY7L7WVJer7sH7hk5//4Gf6zHtPEl+\n"
        "Tr2ub1zNrVbh6e1Bitw7DaGZNX6XEWpyTTsAd42sQWh6o23MC6GyfS1YFsPGHzGe\n"
        "WYQbWn2AZ1mK32z2mLZfVg41qu9RKG20iCyaczZ2YmuYyOkoLHijOAHC8vZbHwYC\n"
        "+lN9Yc8/BoMuMMwDTMDaJD0TsBX02hi9YI7Gu88PMCJO+SRe5400MonUMXTwCa91\n"
        "Tt3RhYpBzx2XGOq5199+oLdTJAaXHJcuB6viKNdSLBuhx6RAEJXZnVexchaHs4Q6\n"
        "HweIv6Et8MjVoqwkaQDmcIGA73qZ0lbUJFZAu2YDJ6TpHc1lHZes763HoMYfuvkX\n"
        "HTSuHZ7edjoWqwnl/vkc3+nG//IEj8LqAacx0i4krDcQpGuQ6BnPfwPFco2NQQpw\n"
        "wHBOL6HrOnD+gGs6DUFwzA==\n"
        "-----END DSA PRIVATE KEY-----\n";

static const char torture_dsa_public_testkey[] =
        "ssh-dss AAAAB3NzaC1kc3MAAACBAJTK9U8SSfdSdkOPMLNLNIelOW3OvQRz7WbP8k"
        "AKMcwEn0L9b8/C8ffKOR+gWGFES+hjsg+fAC7ltzHDxOQhKrthE5DjT0+rDA+/LQ3c"
        "ZSn/6QpLbrwEgn5Uo3nXddF/t4vV7hodQn5qX3HUnFOZzpPQYGrWXK74JNRTKHblo0"
        "MXAAAAFQCvOI9tBplPs3sI0MLCF7lW+gvzxwAAAIBeG4hWwnFRAnmdZBEt/ujdcQZD"
        "4RxWYc7MwHXEKweNiekSGFyj6v8cNlIPfWTMN4BlTJzPfVaoYvzJev45lEuoSwYLt3"
        "AQDM+JcO6XTMdyXTKIo+tGsuA0kd4pxPol+UGeAruNBEhVSDcXfXTh9tVravBqeIuX"
        "gZIFk9cylR2eDwAAAIB4roDQBfgf8AoSAJAb7y8OVvxt5cT7iqaRMQX2XgtW09Nu9R"
        "bUIVS7n2mw3iqZG0xnG3iv1oL9gwNXMLlf+gLmsqU3788jaEZ9IhZ8VdgHAoHm6UWM"
        "7b2uADmhirI6dRZUVO+/iMGUvDxa66OI4hDV055pbwQhtxupUatThyDzIg== "
        "aris@aris-air\n";

static const char torture_dsa_testkey_cert[] =
        "ssh-dss-cert-v01@openssh.com AAAAHHNzaC1kc3MtY2VydC12MDFAb3BlbnNza"
        "C5jb20AAAAgKAd9MpIBrzctQyJvCYYJ2WUD5fyWlXMSv1G/3VihbCAAAACBAJTK9U8"
        "SSfdSdkOPMLNLNIelOW3OvQRz7WbP8kAKMcwEn0L9b8/C8ffKOR+gWGFES+hjsg+fA"
        "C7ltzHDxOQhKrthE5DjT0+rDA+/LQ3cZSn/6QpLbrwEgn5Uo3nXddF/t4vV7hodQn5"
        "qX3HUnFOZzpPQYGrWXK74JNRTKHblo0MXAAAAFQCvOI9tBplPs3sI0MLCF7lW+gvzx"
        "wAAAIBeG4hWwnFRAnmdZBEt/ujdcQZD4RxWYc7MwHXEKweNiekSGFyj6v8cNlIPfWT"
        "MN4BlTJzPfVaoYvzJev45lEuoSwYLt3AQDM+JcO6XTMdyXTKIo+tGsuA0kd4pxPol+"
        "UGeAruNBEhVSDcXfXTh9tVravBqeIuXgZIFk9cylR2eDwAAAIB4roDQBfgf8AoSAJA"
        "b7y8OVvxt5cT7iqaRMQX2XgtW09Nu9RbUIVS7n2mw3iqZG0xnG3iv1oL9gwNXMLlf+"
        "gLmsqU3788jaEZ9IhZ8VdgHAoHm6UWM7b2uADmhirI6dRZUVO+/iMGUvDxa66OI4hD"
        "V055pbwQhtxupUatThyDzIgAAAAAAAAAAAAAAAQAAAA5saWJzc2hfdG9ydHVyZQAAA"
        "AAAAAAAAAAAAP//////////AAAAAAAAAIIAAAAVcGVybWl0LVgxMS1mb3J3YXJkaW5"
        "nAAAAAAAAABdwZXJtaXQtYWdlbnQtZm9yd2FyZGluZwAAAAAAAAAWcGVybWl0LXBvc"
        "nQtZm9yd2FyZGluZwAAAAAAAAAKcGVybWl0LXB0eQAAAAAAAAAOcGVybWl0LXVzZXI"
        "tcmMAAAAAAAAAAAAAARcAAAAHc3NoLXJzYQAAAAMBAAEAAAEBAKKMHL9hp/LTng8sP"
        "5YHTKaAbC7R003VVTjqOR8DBb4/5RZG2ZW+idp/RiBOuBzTxOOb0pyHSWcM+FGH077"
        "ZzSjR6dTIDK4ytWehI8mbBqg2fgYZr3CgOiHJJIQSZw1e1PXTK6LwFoWutWfRqQ6gd"
        "Z2kX28KiUMEkRxdae9Qp39H2SsToQFcdKKYZmBs98d6quD3jmb92JdAB01XUZqpnhC"
        "w1MXrlzdm4Esm/PNcxIHWihx+aFskspD+LsI5+k+xE7i9jLA3Rtx2Rw4Zy8y5n8zmf"
        "3DWnTAq4GrjJbkCnOXWBdk0ng2lMcLp/zTzEAVWXRExywDAYJBpoUVJLn5VQyEAAAE"
        "PAAAAB3NzaC1yc2EAAAEAAt4V9aGqeahOfUvhG7M8/Mn26aLB/HXbICYFJF7dY6urm"
        "SIoS2KBqISCFGXTituiwGlZeAJ+pVgCMYo07Nxtd6oqIjsgKfJqDNx7e4pGw/YJnkm"
        "BqMO/k/ygu2mLmQF0lnpmG2KyjKEljMibHaKlFkcVNbwfOb4p8N3OHm66g5mbCUTRZ"
        "DHqMSJb3YtnObLexD13RydwxkG5AfCnOWxy5O4agXGEYwr/48AQBHYg9obGtpD1qyF"
        "4mMXgzaLViFtcwah6wHGlW0UPQMvrq/RqigAkyUszSccfibkIXJ+wGAgsRYhVAMwME"
        "JqPZ6GHOEIjLBKUegsclHb7Pk0YO8Auaw== "
        "aris@aris-air\n";

/****************************************************************************
 * ECDSA KEYS
 ****************************************************************************/

static const char torture_ecdsa256_private_testkey[] =
        "-----BEGIN EC PRIVATE KEY-----\n"
        "MHcCAQEEIBCDeeYYAtX3EnsP0ratwVpNTaA/4K1N6VvHMiUZlVdhoAoGCCqGSM49\n"
        "AwEHoUQDQgAEx+9ud88Q5GWtLd+yMtYaapC85g+2ZLp7VtFHA0EbNHqBUQxoh+Ik\n"
        "89Mlr7AUxcFPd+kCo+NE6yq/mNQcL7E6iQ==\n"
        "-----END EC PRIVATE KEY-----\n";

static const char torture_ecdsa256_private_testkey_passphrase[] =
        "-----BEGIN EC PRIVATE KEY-----\n"
        "Proc-Type: 4,ENCRYPTED\n"
        "DEK-Info: AES-128-CBC,5C825E6FE821D0DE99D8403F4B4020CB\n"
        "\n"
        "TaUq8Qenb52dKAYcQGIYfdT7Z2DroySk38w51kw/gd8o79ZHaAQv60GtaNoy0203\n"
        "2X1o29E6c0WsY9DKhSHKm/zzvZmL+ChZYqqh3sd1gp55aJsHNN4axiIu2YCbCavh\n"
        "8VZn2VJDaitLy8ARqA/lMGQfqHSa3EOqti9FzWG/P6s=\n"
        "-----END EC PRIVATE KEY-----\n";

static const char torture_ecdsa256_public_testkey[] =
        "ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNT"
        "YAAABBBMfvbnfPEORlrS3fsjLWGmqQvOYPtmS6e1bRRwNBGzR6gVEMaIfiJPPTJa+w"
        "FMXBT3fpAqPjROsqv5jUHC+xOok= aris@kalix86\n";

static const char torture_ecdsa384_private_testkey[] =
        "-----BEGIN EC PRIVATE KEY-----\n"
        "MIGkAgEBBDBY8jEa5DtRy4AVeTWhPJ/TK257behiC3uafEi6YA2oHORibqX55EDN\n"
        "wz29MT40mQSgBwYFK4EEACKhZANiAARXc4BN6BrVo1QMi3+i/B85Lu7SMuzBi+1P\n"
        "bJti8xz+Szgq64gaBGOK9o+WOdLAd/w7p7DJLdztJ0bYoyT4V3B3ZqR9RyGq6mYC\n"
        "jkXlc5YbYHjueBbp0oeNXqsXHNAWQZo=\n"
        "-----END EC PRIVATE KEY-----\n";

static const char torture_ecdsa384_private_testkey_passphrase[] =
        "-----BEGIN EC PRIVATE KEY-----\n"
        "Proc-Type: 4,ENCRYPTED\n"
        "DEK-Info: AES-128-CBC,5C825E6FE821D0DE99D8403F4B4020CB\n"
        "\n"
        "TaUq8Qenb52dKAYcQGIYfdT7Z2DroySk38w51kw/gd8o79ZHaAQv60GtaNoy0203\n"
        "2X1o29E6c0WsY9DKhSHKm/zzvZmL+ChZYqqh3sd1gp55aJsHNN4axiIu2YCbCavh\n"
        "8VZn2VJDaitLy8ARqA/lMGQfqHSa3EOqti9FzWG/P6s=\n"
        "-----END EC PRIVATE KEY-----\n";

static const char torture_ecdsa384_public_testkey[] =
        "ecdsa-sha2-nistp384 AAAAE2VjZHNhLXNoYTItbmlzdHAzODQAAAAIbmlzdHAzOD"
        "QAAABhBFdzgE3oGtWjVAyLf6L8Hzku7tIy7MGL7U9sm2LzHP5LOCrriBoEY4r2j5Y5"
        "0sB3/DunsMkt3O0nRtijJPhXcHdmpH1HIarqZgKOReVzlhtgeO54FunSh41eqxcc0B"
        "ZBmg== aris@kalix86";

static const char torture_ecdsa521_private_testkey[] =
        "-----BEGIN EC PRIVATE KEY-----\n"
        "MIHbAgEBBEG83nSJ2SLoiBvEku1JteQKWx/Xt6THksgC7rrIaTUmNzk+60f0sCCm\n"
        "Gll0dgrZLmeIw+TtnG1E20VZflCKq+IdkaAHBgUrgQQAI6GBiQOBhgAEAc6D728d\n"
        "baQkHnSPtztaRwJw63CBl15cykB4SXXuwWdNOtPzBijUULMTTvBXbra8gL4ATd9d\n"
        "Qnuwn8KQUh2T/z+BARjWPKhcHcGx57XpXCEkawzMYaHUUnRdeFEmNRsbXypsf0mJ\n"
        "KATU3h8gzTMkbrx8DJTFHEIjXBShs44HsSYVl3Xy\n"
        "-----END EC PRIVATE KEY-----\n";

static const char torture_ecdsa521_private_testkey_passphrase[] =
        "-----BEGIN EC PRIVATE KEY-----\n"
        "Proc-Type: 4,ENCRYPTED\n"
        "DEK-Info: AES-128-CBC,24C4F383915BC07D9C63209BF6AD3DEE\n"
        "\n"
        "M+JGfpGfoH3Wn6XWSoHrGGevaS6p2vJGQdkFEIgUfh16s+U/LcRhAhRnhX/MV6Ds\n"
        "OZTpusrjInlZXNUR97fJbmjr/600qUlh4y3U9ikiX3IXE+RI80TPNdishOOjKRF7\n"
        "aWDW8UxTlFfU2Zc1Ew0pTvMXXcuTpozW1NNVY+6S9uWfHwq1/EcR35dbnEmG0gId\n"
        "qsiEdVKh7p+9Qto8jcVWzMh7ANMcIwmxQ4zbvnqypwgAgpMbamWqBZ9q4egsVZKd\n"
        "uRzL95L05ctOBGYNYqpPNIX3UdQU07kzwNC+yaHOb2s=\n"
        "-----END EC PRIVATE KEY-----\n";

static const char torture_ecdsa521_public_testkey[] =
        "ecdsa-sha2-nistp521 AAAAE2VjZHNhLXNoYTItbmlzdHA1MjEAAAAIbmlzdHA1Mj"
        "EAAACFBAHOg+9vHW2kJB50j7c7WkcCcOtwgZdeXMpAeEl17sFnTTrT8wYo1FCzE07w"
        "V262vIC+AE3fXUJ7sJ/CkFIdk/8/gQEY1jyoXB3Bsee16VwhJGsMzGGh1FJ0XXhRJj"
        "UbG18qbH9JiSgE1N4fIM0zJG68fAyUxRxCI1wUobOOB7EmFZd18g== aris@kalix86";

/****************************************************************************
 * ED25519 KEYS
 ****************************************************************************/

static const char torture_ed25519_private_testkey[] =
        "-----BEGIN OPENSSH PRIVATE KEY-----\n"
        "b3BlbnNzaC1rZXktdjEAAAAABG5vbmUAAAAEbm9uZQAAAAAAAAABAAAAMwAAAAtzc2gtZW\n"
        "QyNTUxOQAAACAVlp8bgmIjsrzGC7ZIKBMhCpS1fpJTPgVOjYdz5gIqlwAAAJBzsDN1c7Az\n"
        "dQAAAAtzc2gtZWQyNTUxOQAAACAVlp8bgmIjsrzGC7ZIKBMhCpS1fpJTPgVOjYdz5gIqlw\n"
        "AAAEBgYXKi3utbZKlYyByhM8Ad6CDWrEh1hmyFl0FnCz5hjRWWnxuCYiOyvMYLtkgoEyEK\n"
        "lLV+klM+BU6Nh3PmAiqXAAAADGFyaXNAa2FsaXg4NgE=\n"
        "-----END OPENSSH PRIVATE KEY-----\n";

static const char torture_ed25519_private_testkey_passphrase[] =
        "-----BEGIN OPENSSH PRIVATE KEY-----\n"
        "b3BlbnNzaC1rZXktdjEAAAAACmFlczI1Ni1jYmMAAAAGYmNyeXB0AAAAGAAAABB3FWpQcE\n"
        "KHKq6PcjkxjmKzAAAAEAAAAAEAAAAzAAAAC3NzaC1lZDI1NTE5AAAAIOGFVuOyZBL0T+NR\n"
        "C7qEV9qr6QiGhz2XSXrxuQoU84FgAAAAkBlOVfS5U7FxtBEtxfxQhZjrZAj2z9d4OfGRPl\n"
        "ZfCnAJNEM3BZ3XCabsujhMkqEs9eptRfj41X6NA8aSFs5JYT+JFVfg470FKtpyUmAibMIo\n"
        "JzI41zAncFd1x7bAgO5HBDe3xNsV159D+sXRkWB9Tzk0l4F8SZvInheIS7VSbqH7t1+yDB\n"
        "Y3GsmYTDstmicanQ==\n"
        "-----END OPENSSH PRIVATE KEY-----\n";

static const char torture_ed25519_public_testkey[] =
        "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIBWWnxuCYiOyvMYLtkgoEyEKlLV+klM+"
        "BU6Nh3PmAiqX aris@kalix86";

static const char *torture_get_testkey_internal(enum ssh_keytypes_e type,
                                                int bits,
                                                int with_passphrase,
                                                int pubkey)
{
    switch (type) {
        case SSH_KEYTYPE_DSS:
            if (pubkey) {
                return torture_dsa_public_testkey;
            } else if (with_passphrase) {
                return torture_dsa_private_testkey_passphrase;
            }
            return torture_dsa_private_testkey;
        case SSH_KEYTYPE_RSA:
            if (pubkey) {
                return torture_rsa_public_testkey;
            } else if (with_passphrase) {
                return torture_rsa_private_testkey_passphrase;
            }
            return torture_rsa_private_testkey;
        case SSH_KEYTYPE_ECDSA:
            if (bits == 521) {
                if (pubkey) {
                    return torture_ecdsa521_public_testkey;
                } else if (with_passphrase) {
                    return torture_ecdsa521_private_testkey_passphrase;
                }
                return torture_ecdsa521_private_testkey;
            } else if (bits == 384) {
                if (pubkey) {
                    return torture_ecdsa384_public_testkey;
                } else if (with_passphrase){
                    return torture_ecdsa384_private_testkey_passphrase;
                }
                return torture_ecdsa384_private_testkey;
            }

            if (pubkey) {
                return torture_ecdsa256_public_testkey;
            } else if (with_passphrase){
                return torture_ecdsa256_private_testkey_passphrase;
            }
            return torture_ecdsa256_private_testkey;
        case SSH_KEYTYPE_ED25519:
            if (pubkey) {
                return torture_ed25519_public_testkey;
            } else if (with_passphrase) {
                return torture_ed25519_private_testkey_passphrase;
            }
            return torture_ed25519_private_testkey;
        case SSH_KEYTYPE_DSS_CERT01:
            return torture_dsa_testkey_cert;
        case SSH_KEYTYPE_RSA_CERT01:
            return torture_rsa_testkey_cert;
        case SSH_KEYTYPE_RSA1:
        case SSH_KEYTYPE_UNKNOWN:
            return NULL;
    }

    return NULL;
}

const char *torture_get_testkey(enum ssh_keytypes_e type,
                                int ecda_bits,
                                int with_passphrase)
{
    return torture_get_testkey_internal(type, ecda_bits, with_passphrase, 0);
}

const char *torture_get_testkey_pub(enum ssh_keytypes_e type, int ecda_bits)
{
    return torture_get_testkey_internal(type, ecda_bits, 0, 1);
}

const char *torture_get_testkey_passphrase(void)
{
    return TORTURE_TESTKEY_PASSWORD;
}
